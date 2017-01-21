import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class sendmessage extends eMarazm
{
	public void doGet(
		HttpServletRequest request,
		HttpServletResponse response) throws ServletException,IOException
	{
		getHttpContext(request,response);
		String userID;
		String firstName;
		String lastName;
		String toID=request.getParameter("toID");
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
		session.setAttribute("toID",toID);
		connectDataBase();
		try
		{
			result=executeQuery("select * from users where userID='"+toID+"'");
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
		
		readFile("Web-inf/classes/templates/send_message_template.html");
		
		insertToken(buffer,0,"id=\"toName\">",firstName+" "+lastName);
		
		out.println(buffer);
	}
	
	public void doPost(
		HttpServletRequest request,
		HttpServletResponse response) throws ServletException,IOException
	{
		getHttpContext(request,response);
		String userID;
		String toID;
		String subject=request.getParameter("subject");
		String message=request.getParameter("message");
		String messageDate;
		
		getWriter();
		setContentType("text/html");
		ResultSet result;
		if (getSession(false)==null)
		{
			sendRedirect(INDEX_PAGE);
			return;
		}	
		if ((userID=(String)session.getAttribute("userID"))==null||
			(toID=(String)session.getAttribute("toID"))==null)
		{
			sendRedirect(ERROR_PAGE);
			return;
		}
		
		connectDataBase();
		try
		{
			executeUpdate("insert into messages (fromID,toID,subject,"
				+"message,messageDate) values ('"+userID+"', '"+toID+"', '"
				+formatString(subject)+"', '"+formatString(message)+"', '"+getCurrentTime()+"')");
			session.removeAttribute("toID");
		}
		
		catch (SQLException sqlException)
		{
			sqlException.printStackTrace();
			sendRedirect(ERROR_PAGE);
			return;
		}
		sendRedirect(SENT_PAGE);
	}
}