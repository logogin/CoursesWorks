import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class startcompose extends eMarazm
{
	public void doPost(
		HttpServletRequest request,
		HttpServletResponse response) throws ServletException,IOException
	{
		getHttpContext(request,response);
		String userID;
		String group;
		String testID;
		String testTitle=request.getParameter("testTitle");
		String testTopicID=request.getParameter("testTopic");
		String testTopicName=request.getParameter("topicName");
		String testType=request.getParameter("testType");
		String newTopic=request.getParameter("newTopic");
		ResultSet result;
		
		setContentType("text/html");
		getWriter();
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
			if (newTopic!=null)
			{
				result=executeQuery("select * from test_topics where testTopicName='"
					+formatString(testTopicName)+"'");
				String testIDString="LAST_INSERT_ID()";
				if (!result.next())
					executeUpdate("insert into test_topics (testTopicName) values('"
						+formatString(testTopicName)+"')");
				else
					testIDString=result.getString("testTopicID");
				executeUpdate("insert into tests (ownerID,testTopicID,testTitle,testType)"
					+" values('"+userID+"',"+testIDString+",'"+formatString(testTitle)
					+"','"+testType+"')");
			}
			else
			{
				result=executeQuery("select * from test_topics where testTopicID='"
					+testTopicID+"'");
					if (!result.next())
					{
						sendRedirect(ERROR_PAGE);
						return;
					}
				executeUpdate("insert into tests (ownerID,testTopicID,testTitle,testType)"
					+" values ('"+userID+"','"+formatString(testTopicID)
					+"','"+formatString(testTitle)+"','"+testType+"')");
			}
			result=executeQuery("select * from tests where testID=LAST_INSERT_ID()");
			result.next();
			testID=result.getString("testID");
			executeUpdate("create table test"+testID+" (question varchar(255)"
				+" NOT NULL, amount int DEFAULT '0' NOT NULL, choice1"
				+" varchar(255) NOT NULL, choice2 varchar(255) NULL,"
				+" choice3 varchar(255) NULL, choice4 varchar(255) NULL,"
				+" choice5 varchar(255) NULL, answer1 tinyint DEFAULT '0'"
				+" NOT NULL, answer2 tinyint NULL, answer3 tinyint NULL,"
				+" answer4 tinyint NULL, answer5 tinyint NULL)");
			session.setAttribute("testID",testID);
			session.setAttribute("testType",testType);
			session.setAttribute("totalPoints","0");
			session.setAttribute("total","0");
		}
		catch (SQLException sqlException)
		{
			sqlException.printStackTrace();
			sendRedirect(ERROR_PAGE);
			return;
		}
		addLogEntry("Lector "+userID+" started compose test "+testID);
		readFile("Web-inf/classes/templates/add_question_template.html");
       	insertToken(buffer,0,"testType=",testType);
       	insertToken(buffer,0,"id=\"total\">","0");
      	out.println(buffer);
	}
}