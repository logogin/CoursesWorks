import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class showwelcome extends eMarazm
{
	public void doGet(
		HttpServletRequest request,
		HttpServletResponse response) throws ServletException,IOException
	{
		getHttpContext(request,response);
		String userID;
		String firstName;
		String lastName;
		
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
		
		ResultSet result;
		connectDataBase();
		
		try
		{
			result=executeQuery("select * from users where userID='"+userID
				+"'");
			result.next();
			firstName=result.getString("firstName");
			lastName=result.getString("lastName");
		}
		
		catch (SQLException sqlException)
		{
			sqlException.printStackTrace();
			sendRedirect(ERROR_PAGE);
			return;
		}
		
		readFile("Web-inf/classes/templates/welcome_template.html");
       	
       	insertToken(buffer,0,"id=\"firstName\">",firstName);
       	insertToken(buffer,0,"id=\"lastName\">",lastName);
       	
       	out.println(buffer);
	}
}