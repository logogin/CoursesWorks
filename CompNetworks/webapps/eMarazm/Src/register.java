import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class register extends eMarazm
{
	public void doPost(
		HttpServletRequest request,
		HttpServletResponse response) throws ServletException,IOException
		
	{
		getHttpContext(request,response);
		String userID=null;
		String registerID=request.getParameter("userID");
		String password=request.getParameter("password");
		String firstName=request.getParameter("firstName");
		String lastName=request.getParameter("lastName");
		String email=request.getParameter("email");
		String publicData=request.getParameter("publicData");
		
		getWriter();
		setContentType("text/html");
		if (getSession(false)!=null)
			userID=(String)session.getAttribute("userID");
		ResultSet result;
		
		connectDataBase();
		try
		{	
			result=executeQuery("select * from users where userID='"+registerID+"'");
			if (result.next())
			{
				sendRedirect(EXIST_PAGE);
				return;
			}
			
			if (userID==null)
			{
				executeUpdate("insert into users (userID,password,_group,"
					+"firstName,lastName,email,publicData) values('"
					+registerID+"','"+formatString(password)+"','student','"
					+formatString(firstName)+"','"+formatString(lastName)
					+"','"+formatString(email)+"','"+publicData+"')");
				addLogEntry("New student "+firstName+" "+lastName+" has been registered");
				sendRedirect("login?userID="+registerID+"&password="+password);
				return;
			}
			else
			{
				result=executeQuery("select * from users where userID='"+userID+"' and _group='admin'");
				if (!result.next())
				{
					sendRedirect(NOACCESS_PAGE);
					return;
				}
				executeUpdate("insert into users (userID,password,_group,"
					+"firstName,lastName,email,publicData) values('"
					+formatString(registerID)+"','"+formatString(password)
					+"','lector','"+formatString(firstName)+"','"
					+formatString(lastName)+"','"+formatString(email)
					+"','"+publicData+"')");
				addLogEntry("New lector "+firstName+" "+lastName+" has been registered by "+userID);
			}
		}
		
		catch (SQLException sqlException)
		{
			sqlException.printStackTrace();
			response.sendRedirect(ERROR_PAGE);
			return;	
		}
	
		readFile("Web-inf/classes/templates/register_lector_template.html");
        insertToken(buffer,0,"id=\"firstName\">",firstName);
    	insertToken(buffer,0,"id=\"lastName\">",lastName);
	     	
		out.println(buffer);
	}
	
	public void doGet(
		HttpServletRequest request,
		HttpServletResponse response) throws ServletException,IOException
		
	{
		getHttpContext(request,response);
		String userID=null;
		ResultSet result;
		getWriter();
		setContentType("text/html");
		if (getSession(false)!=null)
			userID=(String)session.getAttribute("userID");
			
		
		if (userID!=null)
		{
			connectDataBase();
			try
			{
				result=executeQuery("select * from users where userID='"
					+userID+"' and _group='admin'");
				if (!result.next())
				{
					sendRedirect(NOACCESS_PAGE);	
					return;
				}
			}
			catch (SQLException sqlException)
			{
				sqlException.printStackTrace();
				sendRedirect(ERROR_PAGE);
				return;
			}
		}
		readFile("Web-inf/classes/templates/register_template.html");
    	out.println(buffer);
	}
}