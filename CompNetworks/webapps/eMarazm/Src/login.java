import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class login extends eMarazm
{
	public void doPost(
		HttpServletRequest request,
		HttpServletResponse response) throws ServletException,IOException
	{
		getHttpContext(request,response);
		String userID=request.getParameter("userID");
		String group;
		String password=request.getParameter("password");
		ResultSet result;
		getSession(true);
		session.removeAttribute("userID");
		session.setMaxInactiveInterval(180);
	
		String firstName;
		String lastName;
		setContentType("text/html");
		getWriter();
		
		connectDataBase();
		try
		{
			result=executeQuery("select * from users where userID='"
				+userID+"' and password='"+formatString(password)+"'");
				
			if (!result.next())
			{
				sendRedirect(BADLOGIN_PAGE);
				return;	
			}
			firstName=result.getString("firstName");
			lastName=result.getString("lastName");
			group=result.getString("_group");
			addLogEntry("User "+firstName+" "+lastName+" logged in");
			if (isGroup(group,LECTOR_GROUP))
			{
				result=executeQuery("select * from tests where finished='0' and ownerID='"+userID+"'");
				while (result.next())
					executeUpdate("drop table if exists test"+result.getString("testID"));
				executeUpdate("delete from tests where finished='0' and ownerID='"+userID+"'");
			}
		}
			
		catch(SQLException sqlException)
		{
			sqlException.printStackTrace();
			sendRedirect(ERROR_PAGE);
			return;
		}
		session.setAttribute("userID",userID);
		
        readFile("Web-inf/classes/templates/main_template.html");
       	
       	insertToken(buffer,0,"name=\"left\" src=\"","showtree");
       	insertToken(buffer,0,"name=\"right\" src=\"","showwelcome");
      		
		out.println(buffer);
	}
	public void doGet(
		HttpServletRequest request,
		HttpServletResponse response) throws ServletException,IOException
	{
		doPost(request,response);
	}
}