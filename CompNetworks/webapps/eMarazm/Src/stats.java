import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class stats extends eMarazm
{
	public void doGet(
		HttpServletRequest request,
		HttpServletResponse response) throws ServletException,IOException
	{
		getHttpContext(request,response);
		String userID;
		ResultSet result;
		StringBuffer testOptions=new StringBuffer();
		StringBuffer topicOptions=new StringBuffer();
		
		getWriter();
		setContentType("text/html");
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
			result=executeQuery("select * from users where userID='"+userID+"' and _group='lector'");
			if (!result.next())
			{
				sendRedirect(NOACCESS_PAGE);
				return;
			}
			result=executeQuery("select * from tests where ownerID='"+userID+"'");
			while (result.next())
				testOptions.append("<option value=\""+result.getString("testID")
					+"\"> "+result.getString("testTitle")+"</option>\n");
			result=executeQuery("select test_topics.testTopicID,test_topics.testTopicName from"+
					" test_topics,tests where tests.ownerID='"+userID
					+"' and tests.testTopicID=test_topics.testTopicID");
			while (result.next())
				topicOptions.append("<option value=\""+result.getString("testTopicID")
					+"\"> "+result.getString("testTopicName")+"</option>\n");
		}
		catch (SQLException sqlException)
		{
			sqlException.printStackTrace();
			sendRedirect(ERROR_PAGE);
			return;
		}
		readFile("Web-inf/classes/templates/stats_template.html");
		insertToken(buffer,0,"id=\"testTitle\">",testOptions.toString());
		insertToken(buffer,0,"id=\"testTopicName\">",topicOptions.toString());
		out.println(buffer);
	}
	
	public void doPost(
		HttpServletRequest request,
		HttpServletResponse response) throws ServletException,IOException
	{
		getHttpContext(request,response);
		String userID;
		String testID=request.getParameter("testTitle");
		String testTopicID=request.getParameter("testTopicName");
		String logic=request.getParameter("logic");
		String testStatus=request.getParameter("testStatus");
		String grade=request.getParameter("grade");
		String gradeValue=request.getParameter("gradeValue");
		String gradeValue1=request.getParameter("gradeValue1");
		String gradeValue2=request.getParameter("gradeValue2");
		String sort=request.getParameter("sort");
		String order=request.getParameter("order");
		boolean flagGrade=false;
		boolean flagStatus=false;
		int counter=0;
		ResultSet result;
		StringBuffer table=new StringBuffer();
		
		getWriter();
		setContentType("text/html");
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
			result=executeQuery("select * from users where userID='"+userID+"' and _group='lector'");
			if (!result.next())
			{
				sendRedirect(NOACCESS_PAGE);
				return;
			}
			if (grade.equals("value"))
			{
				grade="grade='"+gradeValue+"'";
				flagGrade=true;
			}
			if (grade.equals("range"))
			{
				grade="(grade>='"+gradeValue1+"' and grade<='"+gradeValue2+"')";
				flagGrade=true;
			}
			if (!testStatus.equals("any"))
			{
				testStatus="grades.finished='"+testStatus+"'";
				flagStatus=true;
			}
			
			if (!flagGrade&&!flagStatus)
				logic="";
			if (!flagGrade&&flagStatus)
				logic=" and "+testStatus+" ";
			if (!flagStatus&&flagGrade)
				logic=" and "+grade+" ";
			if (flagStatus&&flagGrade)
				logic=" and ("+testStatus+" "+logic+" "+grade+") ";
			if (!testID.equals("any"))
				testID="and tests.testID='"+testID+"' ";
			else
				testID="";
			if (!testTopicID.equals("any"))
				testTopicID="and test_topics.testTopicID='"+testTopicID+"' ";
			else
				testTopicID="";
				
			result=executeQuery("select concat(firstName,\" \",lastName)"
				+" as name,userID,firstName,lastName,testTitle,testTopicName,grades.finished"
				+" as status,curQuestion,grade,testDate from users,"
				+"test_topics,tests,grades where (ownerID='"+userID
				+"' and tests.testTopicID=test_topics.testTopicID "
				+testTopicID+"and tests.testID=grades.testID "
				+testID+"and userID=studentID) "+logic+"order by "+sort+" "+order);
			while (result.next())
			{
				String status;
				if (result.getString("status").equals("1"))
					status="Finished";
				else
					status="Not finished";
				counter++;
				table.append("<tr><td align=\"right\" bgcolor=\"EDEDEF\">"+Integer.toString(counter)+".</td>\n");
				table.append("<td bgcolor=\"EDEDEF\"><a href=\"userinfo?userID="+result.getString("userID")
					+"\" target=_blank title=\"Get info about "
       				+result.getString("firstName")+" "+result.getString("lastName")
       				+"\">"+result.getString("firstName")+" "+result.getString("lastName")+"</a></td>\n");
				table.append("<td bgcolor=\"EDEDEF\">"+result.getString("testTitle")+"</td>\n");
				table.append("<td bgcolor=\"EDEDEF\">"+result.getString("testTopicName")+"</td>\n");
				table.append("<td bgcolor=\"EDEDEF\">"+status+"</td>\n");
				table.append("<td bgcolor=\"EDEDEF\">"+result.getString("curQuestion")+"</td>\n");
				table.append("<td bgcolor=\"EDEDEF\">"+result.getString("grade")+"</td>\n");
				table.append("<td bgcolor=\"EDEDEF\">"+result.getString("testDate")+"</td></tr>\n");
			}
		}
		catch (SQLException sqlException)
		{
			sqlException.printStackTrace();
			sendRedirect(ERROR_PAGE);
			return;
		}
		readFile("Web-inf/classes/templates/stats_results_template.html");
		insertToken(buffer,0,"id=\"rows\">",Integer.toString(counter));
		insertToken(buffer,0,"id=\"table\">",table.toString());
		out.println(buffer);
	}
}