import java.io.*;
import java.util.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class dotest extends eMarazm
{
	public StringBuffer createQuestion(int curQuestion,int testType,
		int totalPoints,String userID) 
			throws IOException,SQLException
	{	
		String testID=request.getParameter("testID");
		int amount;
		int count;
		int finished=1;
		int points=0;
		int current_points=0;
		float grade;
		boolean finishForm=false;
		String testDate;
		String testTitle;
		ResultSet result;
				
		if (request.getParameter("questionAnswer")!=null)
		{
			result=executeQuery("select count(*) from test"+testID);
			result.next();
			count=result.getInt("count(*)");
			
			result=executeQuery("select * from test"+testID);
			result.absolute(curQuestion);
			amount=result.getInt("amount");
			
			if (testType==SINGLE_CHOICE)
			{
				String answer=request.getParameter("answer");
				if (result.getInt("answer"+answer)==1)
					current_points=1;
			}
			else
			{
				for (int i=0; i<amount; i++)
				{
					String col_name="answer"+Integer.toString(i+1);
					if (request.getParameter(col_name)!=null
						&&request.getParameter(col_name).equals("on")
						&&result.getInt(col_name)==1)
						current_points++;
					else
						current_points--;
				}
			}
			result=executeQuery("select * from grades where studentID='"
				+userID+"' and testID='"+testID+"'");
			result.next();
			points=result.getInt("points");
			if (current_points<0)
				current_points=0;
			points+=current_points;
			if (curQuestion==count)
			{
				finished=1;
				finishForm=true;
				
				grade=100.0f*points/totalPoints;
				executeUpdate("update grades set curQuestion='"+curQuestion
					+"', grade='"+grade+"', points='"+points
					+"', finished='1', testDate='"+getCurrentTime()
					+"' where studentID='"+userID+"' and testID='"
					+testID+"'");
			}
			else
			{
				curQuestion++;
				finishForm=false;
				executeUpdate("update grades set curQuestion='"+curQuestion
					+"', points='"+points+"' where studentID='"+userID
					+"' and testID='"+testID+"'");
			}
			
		}
		if (!finishForm)
		{
			readFile("Web-inf/classes/templates/question_template.html");
			
       		result=executeQuery("select count(*) from test"+testID);
			result.next();
			count=result.getInt("count(*)");
			
			result=executeQuery("select * from test"+testID);
			result.absolute(curQuestion);
			amount=result.getInt("amount");
			
			insertToken(buffer,0,"amount=",Integer.toString(amount));
			insertToken(buffer,0,"testType=",Integer.toString(testType));
			insertToken(buffer,0,"id=\"curQuestion\">",
				Integer.toString(curQuestion));
			insertToken(buffer,0,"id=\"total_number\">",
				Integer.toString(count));
			insertToken(buffer,0,"id=\"question\">",
				result.getString("question"));
			StringBuffer table=new StringBuffer();
			for (int i=0; i<amount; i++)
			{
				table.append("<tr>");
				table.append("<td>");
				if (testType==SINGLE_CHOICE)
					table.append("<input type=\"radio\" name=\"answer\" id=\"answer"
						+(i+1)+"\" value=\""+(i+1)+"\"/><label for=\"answer"+(i+1)+"\">");
				else
					table.append("<input type=\"checkbox\" name=\"answer\""
						+(i+1)+"\" id=\"answer"+(i+1)+"\"/><label for=\"answer"+(i+1)+"\">");
				table.append(result.getString("choice"+(i+1))+"</label>");
				table.append("</td>");
				table.append("</tr>");
			}
			insertToken(buffer,0,"id=\"choices\">",table.toString());
			insertToken(buffer,0,"name=\"testID\" value=\"",testID);
			
		}
		else
		{
			result=executeQuery("select * from grades where studentID='"
				+userID+"' and testID='"+testID+"'");
			result.next();
			grade=result.getFloat("grade");
			testDate=result.getString("testDate");
			
			result=executeQuery("select * from tests where testID='"+testID+"'");
			result.next();
			testTitle=result.getString("testTitle");
			readFile("Web-inf/classes/templates/finished_template.html");
       		insertToken(buffer,0,"id=\"testTitle\">",testTitle);
       		insertToken(buffer,0,"id=\"testDate\">",testDate);
       		insertToken(buffer,0,"id=\"grade\">",Float.toString(grade));
       		addLogEntry("Student "+userID+" finished test "+testID);
		}
		return buffer;
	}
	
	public void doPost(
		HttpServletRequest request,
		HttpServletResponse response) throws ServletException,IOException
	{
		getHttpContext(request,response);
		String userID;
		setContentType("text/html");
		getWriter();
		
		String testID=request.getParameter("testID");
		int finished=0;
		int totalPoints;
		int curQuestion;
		int testType;
				
		ResultSet result;
		if (getSession(false)==null)
		{
			sendRedirect(INDEX_PAGE);
			return;
		}
		if ((userID=(String)session.getAttribute("userID"))==null)
		{
			sendRedirect(ERROR_PAGE);
			return;
		}
		
		connectDataBase();
		
		try
		{
			result=executeQuery("select * from users where userID='"+userID+"' and _group='student'");
			if (!result.next())
			{
				sendRedirect(NOACCESS_PAGE);
				return;
			}
			result=executeQuery("select * from grades where studentID='"+userID
				+"' and testID='"+testID+"'");
			if (result.next())
			{
				finished=result.getInt("finished");
				if (finished==1)
				{
					sendRedirect(ERROR_PAGE);
					return;
				}
				else
					curQuestion=result.getInt("curQuestion");
			}
			else
			{
				executeUpdate("insert into grades (studentID,testID)"
					+" values ("+userID+","+testID+")");
				curQuestion=1;
				addLogEntry("Student "+userID+" started test "+testID);
			}
			
			result=executeQuery("select * from tests where testID='"+testID+"'");
			result.next();
			testType=result.getInt("testType");
			totalPoints=result.getInt("totalPoints");
		}
		catch (SQLException sqlException)
		{
			sqlException.printStackTrace();
			sendRedirect(ERROR_PAGE);
			return;
		}
		try
		{
			createQuestion(curQuestion,testType,totalPoints,userID);
		}
		catch (SQLException sqlException)
		{
			sqlException.printStackTrace();
			sendRedirect(ERROR_PAGE);
			return;
		}
		out.println(buffer);
	}
}