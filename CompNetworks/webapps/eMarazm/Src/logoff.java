import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class logoff extends eMarazm
{
	public void doGet(
		HttpServletRequest request,
		HttpServletResponse response) throws ServletException,IOException
	{
		getHttpContext(request,response);
		String userID=null;
		getWriter();
		setContentType("text/html");
		connectDataBase();
		if (getSession(false)!=null)
		{
			userID=(String)session.getAttribute("userID");
			session.removeAttribute("userID");
			session.invalidate();
		}	
		if (userID!=null)
			addLogEntry("User "+userID+" logged off");
		else
			addLogEntry("User log off");
		
		sendRedirect("/eMarazm/index.html");
	}
}