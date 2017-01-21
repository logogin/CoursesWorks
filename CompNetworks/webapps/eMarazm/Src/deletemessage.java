import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class deletemessage extends eMarazm
{
	public void doGet(
		HttpServletRequest request,
		HttpServletResponse response) throws ServletException,IOException
	{
		getHttpContext(request,response);
		String userID;
		String messageID=request.getParameter("messageID");
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
			result=executeQuery("select * from messages where toID='"+userID+"'");
			if (!result.next())
			{
				sendRedirect(NOACCESS_PAGE);
				return;
			}
			
			executeUpdate("delete from messages where messageID='"
				+messageID+"' and toID='"+userID+"'");
		}
		
		catch (SQLException sqlException)
		{
			sqlException.printStackTrace();
			sendRedirect(ERROR_PAGE);
			return;
		}
		
		sendRedirect("viewmessages");
	}
}