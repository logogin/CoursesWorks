import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class viewmessage extends eMarazm
{
	public void doGet(
		HttpServletRequest request,
		HttpServletResponse response) throws ServletException,IOException
	{
		getHttpContext(request,response);
		String userID;
		String messageID=request.getParameter("messageID");
		String fromID;
		String subject;
		String messageDate;
		String firstName;
		String lastName;
		String message;
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
		
		StringBuffer table=new StringBuffer();
		try
		{
			result=executeQuery("select * from messages where toID='"
				+userID+"' and messageID='"
				+messageID+"'");
			if (!result.next())
			{
				sendRedirect(NOACCESS_PAGE);
				return;
			}
			
			subject=result.getString("subject");
			message=result.getString("message");
			messageDate=result.getString("messageDate");
			if (result.getInt("unRead")==1)
				executeUpdate("update messages set unRead='0' where messageID='"
					+messageID+"' and toID='"+userID+"'");
			fromID=result.getString("fromID");
			result=executeQuery("select * from users where userID='"+fromID+"'");
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
		
		readFile("Web-inf/classes/templates/view_message_template.html");
		
		insertToken(buffer,0,"id=\"fromName\">",firstName+" "+lastName);
		insertToken(buffer,0,"id=\"messageDate\">",messageDate);
		insertToken(buffer,0,"id=\"subject\">",subject);
		insertToken(buffer,0,"id=\"message\">",message);
		insertToken(buffer,0,"deletemessage?messageID=",messageID);
		
		out.println(buffer);
	}
}	
