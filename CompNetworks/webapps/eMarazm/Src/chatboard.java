import java.io.*;
import java.util.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class chatboard extends eMarazm
{
	public void doGet(
		HttpServletRequest request,
		HttpServletResponse response) throws ServletException,IOException
	{
		getHttpContext(request,response);
		getContext();
		getServletContext();
		String userID;
		Vector messages=null;
		
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
		
		if ((messages=(Vector)context.getAttribute("messages"))==null)
		{
			messages=new Vector();
			context.setAttribute("messages",messages);
		}
		
		StringBuffer text=new StringBuffer();
		for (int i=0; i<messages.size(); i++)
			text.append((String)messages.elementAt(i)+"<br>");
			
		readFile("Web-inf/classes/templates/chat_board_template.html");
       	insertToken(buffer,0,"id=\"messages\">",text.toString());
       	out.println(buffer);
	}
}