import java.io.*;
import java.net.*;
import java.util.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class userinfo extends eMarazm
{
	public void doGet(
		HttpServletRequest request,
		HttpServletResponse response) throws ServletException,IOException
	{
		getHttpContext(request,response);
		String userID;
		String userForInfoID=request.getParameter("userID");
		String group;
		String userForInfoGroup;
		String firstName;
		String lastName;
		String email;
		int publicData;
		
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
			result=executeQuery("select * from users where userID='"
				+userID+"'");
			result.next();
			group=result.getString("_group");
			
			result=executeQuery("select * from users where userID='"
				+userForInfoID+"'");
			result.next();
			
			firstName=result.getString("firstName");
			lastName=result.getString("lastName");
			userForInfoGroup=result.getString("_group");
			publicData=result.getInt("publicData");
			email=result.getString("email");
		}
		catch (SQLException sqlException)
		{
			sqlException.printStackTrace();
			sendRedirect(ERROR_PAGE);
			return;	
		}
		
		readFile("Web-inf/classes/templates/user_info_template.html");
       	
       	insertToken(buffer,0,"href=\"sendmessage?toID=",userForInfoID);
       	if (isGroup(group,ADMIN_GROUP))
       	{
       		insertToken(buffer,0,"id=\"name\">",firstName+" "+lastName);
       		insertToken(buffer,0,"id=\"group\">",getGroupString(userForInfoGroup));
       		insertToken(buffer,0,"id=\"email\">","<a href=\"sendmail?toID="
       			+userForInfoID+"\" title=\"Send mail to "
       				+firstName+" "+lastName+"\">"+email+"</a>");
       		if (publicData==1)
       			insertToken(buffer,0,"id=\"publicData\">","Yes");
       		else
       			insertToken(buffer,0,"id=\"publicData\">","No");
       		out.println(buffer);
       		return;
       	}
       	
       	if (publicData==1)
       	{
       		insertToken(buffer,0,"id=\"name\">",firstName+" "+lastName);
       		insertToken(buffer,0,"id=\"group\">",getGroupString(userForInfoGroup));
       		insertToken(buffer,0,"id=\"email\">","<a href=\"sendmail?toID="
       			+userForInfoID+"\" title=\"Send mail to "
       				+firstName+" "+lastName+"\">"+email+"</a>");
       		insertToken(buffer,0,"id=\"publicData\">","Yes");
       	}
       	else
       	{
       		insertToken(buffer,0,"id=\"publicDataMessage\">","User info is disable"
       			+" or/and unavailable");
       		insertToken(buffer,0,"id=\"name\">","N/A");
       		insertToken(buffer,0,"id=\"group\">","N/A");       			
       		insertToken(buffer,0,"id=\"email\">","N/A");
       		insertToken(buffer,0,"id=\"publicData\">","N/A");
       	}
       	out.println(buffer);
	}
}