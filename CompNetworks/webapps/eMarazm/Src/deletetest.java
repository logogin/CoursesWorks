import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class deletetest extends eMarazm
{
	public void doPost(
		HttpServletRequest request,
		HttpServletResponse response) throws ServletException,IOException
	{
		getHttpContext(request,response);
		String userID;
		String group;
		String testID=request.getParameter("testID");
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
			result=executeQuery("select * from users where userID='"+userID+"' and _group='admin'");
			if (!result.next())
			{
				sendRedirect(NOACCESS_PAGE);
				return;
			}
			
			executeUpdate("delete from tests where testID='"+testID+"'");
			executeUpdate("delete from grades where testID='"+testID+"'");
			executeUpdate("drop table if exists test"+testID);
			addLogEntry("Test "+testID+" has been deleted by "+userID);
		}
		catch (SQLException sqlException)
		{
			sqlException.printStackTrace();
			sendRedirect(ERROR_PAGE);
			return;	
		}
		
		sendRedirect(UPDATED_PAGE);
	}
}