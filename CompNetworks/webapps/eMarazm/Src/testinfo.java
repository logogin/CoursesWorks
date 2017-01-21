import java.io.*;
import java.net.*;
import java.util.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class testinfo extends eMarazm
{
	public void doGet(
		HttpServletRequest request,
		HttpServletResponse response) throws ServletException,IOException
	{
		getHttpContext(request,response);
		String userID;
		String group;
		String testID=request.getParameter("testID");
		String testTitle;
		String testTopicName;
		int testType;
		int finished=1;
		float grade=0.0f;
		boolean bStart=false;
		boolean bContinue=false;
		String testTopicID;
		String creationDate=null;
		String testDate=null;
		String ownerID;
		String firstName;
		String lastName;
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
			result=executeQuery("select * from users where userID='"+userID+"'");
			result.next();
			group=result.getString("_group");
			
			result=executeQuery("select * from tests where testID='"+testID+"'");
			result.next();
			
			ownerID=result.getString("ownerID");
			testTopicID=result.getString("testTopicID");
			testTitle=result.getString("testTitle");
			testType=result.getInt("testType");
			creationDate=result.getString("creationDate");
						
			result=executeQuery("select * from test_topics where"+
				" testTopicID='"+testTopicID+"'");
			result.next();
			testTopicName=result.getString("testTopicName");
			
			result=executeQuery("select * from users where userID='"
				+ownerID+"'");
			result.next();
			firstName=result.getString("firstName");
			lastName=result.getString("lastName");
			
			if (isGroup(group,STUDENT_GROUP))
			{
				result=executeQuery("select * from grades where studentID='"
					+userID+"' and testID='"+testID+"'");
				if (!result.next())
					bStart=true;
				else
				{
					testDate=result.getString("testDate");
					finished=result.getInt("finished");
					grade=result.getFloat("grade");
				}
				if (finished==0)
					bContinue=true;
			}
		}
		catch (SQLException sqlException)
		{
			sqlException.printStackTrace();
			sendRedirect(ERROR_PAGE);
			return;	
		}
		
		readFile("Web-inf/classes/templates/test_info_template.html");
       	insertToken(buffer,0,"id=\"testTitle\">",testTitle);
       	insertToken(buffer,0,"id=\"testTopicName\">",testTopicName);
       	if (testType==0)
       		insertToken(buffer,0,"id=\"testType\">",
       			"Single choice");
       	else
       		insertToken(buffer,0,"id=\"testType\">",
       			"Multiple choice");
       	insertToken(buffer,0,"userinfo?userID=",
       		ownerID+"\" target=_blank title=\"Get info about "
       		+firstName+" "+lastName+"\">"+firstName+" "+lastName);
       	insertToken(buffer,0,"id=\"creationDate\">",
       		creationDate);
       	if (isGroup(group,STUDENT_GROUP)&&!bStart&&!bContinue)
       	{
       		insertToken(buffer,0,"id=\"testDate\">",testDate);
       		insertToken(buffer,0,"id=\"grade\">",Float.toString(grade));
       	}
       	else
       	{
       		insertToken(buffer,0,"id=\"testDate\">","N/A");
       		insertToken(buffer,0,"id=\"grade\">","N/A");
       	}
       	
       	if (isGroup(group,STUDENT_GROUP)&&(bStart||bContinue))
       	{
       		insertToken(buffer,0,"id=\"formDefinition\" style=\"",
       			"display:block");
       		insertToken(buffer,0,"action=\"","dotest");
       		insertToken(buffer,0,"name=\"testID\" value=\"",testID);
       		if (bStart)
       			insertToken(buffer,0,"type=\"submit\" value=\"",
       					"Start test");
       		if (bContinue)
       			insertToken(buffer,0,"type=\"submit\" value=\"",
       					"Continue test");
      	}
       	
       	if (isGroup(group,STUDENT_GROUP)&&finished==1)
       		insertToken(buffer,0,"id=\"formDefinition\" style=\"","display:none");
       	if (isGroup(group,ADMIN_GROUP))
       	{
       		insertToken(buffer,0,"id=\"formDefinition\" style=\"","display:block");
       		insertToken(buffer,0,"action=\"","deletetest");
       		insertToken(buffer,0,"name=\"testID\" value=\"",testID);
       		insertToken(buffer,0,"type=\"submit\" value=\"","Delete test");
       	}
       	if (isGroup(group,LECTOR_GROUP))
       		insertToken(buffer,0,"id=\"formDefinition\" style=\"","display:none");
       	out.println(buffer);
	}
}