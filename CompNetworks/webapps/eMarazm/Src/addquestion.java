import java.io.*;
import java.util.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class addquestion extends eMarazm
{
	public void doPost(
		HttpServletRequest request,
		HttpServletResponse response) throws ServletException,IOException
	{
		getHttpContext(request,response);
		String userID;
		String testID;
		String testType=null;
		int total;
		int totalPoints;
		String creationDate=null;
		String group;
		String choice[]=new String[5];
		String answer[]=new String[5];
		String lastQuestion=request.getParameter("lastQuestion");
		boolean last;
		if (lastQuestion!=null)
			last=true;
		else
			last=false;
		int amount=Integer.parseInt(request.getParameter("amount"));
		
		ResultSet result;
		
		getWriter();
		setContentType("text/html");
		if (getSession(false)==null)
		{
			sendRedirect(INDEX_PAGE);
			return;
		}
			
		if ((userID=(String)session.getAttribute("userID"))==null||
			(testID=(String)session.getAttribute("testID"))==null||
			(testType=(String)session.getAttribute("testType"))==null||
			(String)session.getAttribute("totalPoints")==null||
			(String)session.getAttribute("total")==null)
		{
			sendRedirect(ERROR_PAGE);
			return;
		}
		
		totalPoints=Integer.parseInt((String)session.getAttribute("totalPoints"));
		total=Integer.parseInt((String)session.getAttribute("total"));
		connectDataBase();
		try
		{
			result=executeQuery("select * from users where userID='"+userID+"' and _group='lector'");
			if (!result.next())
			{
				response.sendRedirect(NOACCESS_PAGE);
				return;
			}
			for (int i=0; i<amount; i++)
			{
				choice[i]=request.getParameter("choice"+(i+1));
				if (request.getParameter("answer"+(i+1))!=null)
				{	
					answer[i]="1";
					totalPoints++;
				}
				else
					answer[i]="0";
			}
			
			if (testType.equals("0"))
			{
				answer[(Integer.parseInt(request.getParameter("answer")))-1]="1";
				totalPoints++;
			}
			executeUpdate("insert into test"+testID+" (question,amount,"
				+"choice1,choice2,choice3,choice4,choice5,answer1,answer2,"
				+"answer3,answer4,answer5) values ('"
				+formatString(request.getParameter("question"))+"','"+amount
				+"','"+formatString(choice[0])+"','"+formatString(choice[1])
				+"','"+formatString(choice[2])+"','"+formatString(choice[3])
				+"','"+formatString(choice[4])+"','"+answer[0]+"','"+answer[1]+"','"+answer[2]
				+"','"+answer[3]+"','"+answer[4]+"')");
			if (last)
			{
				creationDate=getCurrentTime();
				executeUpdate("update tests set totalPoints='"+totalPoints
					+"', finished='1', creationDate='"+creationDate
					+"' where ownerID='"+userID+"' and testID='"+testID+"'");
				session.removeAttribute("testID");
				session.removeAttribute("testType");
				session.removeAttribute("totalPoints");
				session.removeAttribute("total");
			}
			total++;
			session.setAttribute("totalPoints",Integer.toString(totalPoints));
			session.setAttribute("total",Integer.toString(total));
		}
		catch (SQLException sqlException)
		{
			sqlException.printStackTrace();
			sendRedirect(ERROR_PAGE);
			return;
		}
		
		String template;
		if (last)
			template="finish_compose_template.html";
		else
			template="add_question_template.html";
		readFile("Web-inf/classes/templates/"+template);
		
       	if (last)
       	{
       		addLogEntry("Lector "+userID+" finished compose test "+testID);
       		insertToken(buffer,0,"id=\"total\">",Integer.toString(total));
       		insertToken(buffer,0,"id=\"creationDate\">",creationDate);
       	}
       	else
       	{
       		insertToken(buffer,0,"testType=",testType);
       		insertToken(buffer,0,"id=\"total\">",Integer.toString(total));
       	}
       	
      	out.println(buffer);
	}
}