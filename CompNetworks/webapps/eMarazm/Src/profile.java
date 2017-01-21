import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class profile extends eMarazm
{
	public void doGet(
		HttpServletRequest request,
		HttpServletResponse response) throws ServletException,IOException
	{
		getHttpContext(request,response);
		String userID;
		String firstName;
		String lastName;
		String email;
		String unRead;
		String group;
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
			firstName=result.getString("firstName");
			lastName=result.getString("lastName");
			email=result.getString("email");
			result=executeQuery("select count(*) from messages where toID='"+userID+"' and unread='1'");
			if (result.next())
				unRead=result.getString("count(*)");
			else
				unRead="0";
		}
		catch (SQLException sqlException)
		{
			sqlException.printStackTrace();
			sendRedirect(ERROR_PAGE);
			return;
		}
		
		readFile("Web-inf/classes/templates/profile_template.html");
       	
       	if (isGroup(group,LECTOR_GROUP))
       	{
       		insertToken(buffer,0,"id=\"compose\">","<input type=\"button\""
       			+" value=\"Compose test\" onClick=\"window.open('composetest','right')\">");
       		insertToken(buffer,0,"id=\"stats\">","<input type=\"button\""
       			+" value=\"Statistics\" onClick=\"window.open('stats','right')\">");
       	}
       	if (isGroup(group,ADMIN_GROUP))
       	{
       		insertToken(buffer,0,"id=\"register\">","<input type=\"button\""
       			+" value=\"Register new lector\" onclick=\"window.open('register','right')\"/>");
       		insertToken(buffer,0,"id=\"logs\">","<input type=\"button\""
       			+" value=\"View system logs\" onclick=\"window.open('viewlog','right')\">");
       		insertToken(buffer,0,"id=\"console\">","<input type=\"button\""
       			+" value=\"SQL Console\" onclick=\"window.open('console','right')\">");
       	}
       	insertToken(buffer,0,"id=\"userID\">",userID);
       	insertToken(buffer,0,"id=\"firstName\">",firstName);
       	insertToken(buffer,0,"id=\"lastName\">",lastName);
       	insertToken(buffer,0,"id=\"email\">",email);
       	insertToken(buffer,0,"id=\"group\">",getGroupString(group));
       	insertToken(buffer,0,"id=\"unRead\">",unRead);
       	out.println(buffer);
	}
}