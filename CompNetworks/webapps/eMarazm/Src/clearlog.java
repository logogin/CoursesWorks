import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class clearlog extends eMarazm
{
	public void doGet(
		HttpServletRequest request,
		HttpServletResponse response) throws ServletException,IOException
	{
		getHttpContext(request,response);
		String userID;
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
			result=executeQuery("select * from users where userID='"+userID+"' and _group='admin'");
			if (!result.next())
			{
				sendRedirect(NOACCESS_PAGE);
				return;
			}
			executeUpdate("delete from logs");
		}
		catch (SQLException sqlException)
		{
			sqlException.printStackTrace();
			sendRedirect(ERROR_PAGE);
			return;
		}
		sendRedirect("viewlog");
	}
}