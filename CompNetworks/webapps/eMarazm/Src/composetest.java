import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class composetest extends eMarazm
{
	public void doGet(
		HttpServletRequest request,
		HttpServletResponse response) throws ServletException,IOException
	{
		getHttpContext(request,response);
		String userID;
		String group;
		String testTopicID;
		String testTopicName;
		ResultSet result;
		StringBuffer options=new StringBuffer();
		
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
			result=executeQuery("select * from test_topics");
       		while(result.next())
       		{
       			testTopicID=result.getString("testTopicID");
       			testTopicName=result.getString("testTopicName");
       			options.append("<option value=\""+testTopicID+"\">"+testTopicName+"</option>");
       		}
		}
		catch (SQLException sqlException)
		{
			sqlException.printStackTrace();
			response.sendRedirect(ERROR_PAGE);
			return;
		}
		readFile("Web-inf/classes/templates/compose_test_template.html");
		insertToken(buffer,0,"name=\"testTopic\">",options.toString());
	   	out.println(buffer);
	}
}