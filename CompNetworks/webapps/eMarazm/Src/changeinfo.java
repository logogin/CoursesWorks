import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class changeinfo extends eMarazm
{
	public void doPost(
		HttpServletRequest request,
		HttpServletResponse response) throws ServletException,IOException
		
	{
		getHttpContext(request,response);
		String userID;
		String oldPassword=request.getParameter("oldPassword");
		String newPassword=request.getParameter("newPassword");
		String firstName=request.getParameter("firstName");
		String lastName=request.getParameter("lastName");
		String email=request.getParameter("email");
		String publicData=request.getParameter("publicData");
		ResultSet result;
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
			result=executeQuery("select * from users where userID='"+userID
				+"' and password='"+oldPassword+"'");
			if (!result.next())
			{
				sendRedirect(BADLOGIN_PAGE);
				return;
			}
			executeUpdate("update users set password='"+newPassword
				+"', firstName='"+formatString(firstName)+"', lastName='"
				+formatString(lastName)+"', email='"+formatString(email)+"', publicData='"
				+publicData+"' where userID='"+userID+"'");
			addLogEntry("User "+userID+" personal data has been updated");
		}
		
		catch (SQLException sqlException)
		{
			sqlException.printStackTrace();
			sendRedirect(ERROR_PAGE);
			return;	
		}
	
		sendRedirect(UPDATED_PAGE);
	}
	
	public void doGet(
		HttpServletRequest request,
		HttpServletResponse response) throws ServletException,IOException
		
	{
		getHttpContext(request,response);
		String userID;
		String firstName;
		String lastName;
		String email;
		String publicData;
		ResultSet result;
		
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
			result=executeQuery("select * from users where userID='"+userID+"'");
			if (!result.next())
			{
				sendRedirect(ERROR_PAGE);
				return;
			}
			firstName=result.getString("firstName");
			lastName=result.getString("lastName");
			email=result.getString("email");
			publicData=result.getString("publicData");
		}
		
		catch (SQLException sqlException)
		{
			sqlException.printStackTrace();
			sendRedirect(ERROR_PAGE);
			return;	
		}
	
		readFile("Web-inf/classes/templates/change_info_template.html");
		insertToken(buffer,0,"id=\"userID\">",userID);
        insertToken(buffer,0,"name=\"firstName\" value=\"",firstName);
        insertToken(buffer,0,"name=\"lastName\" value=\"",lastName);
        insertToken(buffer,0,"name=\"email\" value=\"",email);
        if (publicData.equals("1"))
        	insertToken(buffer,0,"name=\"publicData\" value=\"1\""," checked");
        else
        	insertToken(buffer,0,"name=\"publicData\" value=\"0\""," checked");
		out.println(buffer);
	}
}