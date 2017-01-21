import java.io.*;
import java.util.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class chatmessage extends eMarazm
{
	public void doGet(
		HttpServletRequest request,
		HttpServletResponse response) throws ServletException,IOException
	{
		getHttpContext(request,response);
		String userID;
		String firstName;
		String lastName;
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
			response.sendRedirect(ERROR_PAGE);
			return;
		}
		
		connectDataBase();
		try
		{
			result=executeQuery("select * from users where userID='"+userID+"'");
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
			
		readFile("Web-inf/classes/templates/chat_message_template.html");
       	insertToken(buffer,0,"name=\"nickName\" value=\"",firstName+" "+lastName);
       	     		
		out.println(buffer);
	}
	public void doPost(
		HttpServletRequest request,
		HttpServletResponse response) throws ServletException,IOException
	{
		getHttpContext(request,response);
		getContext();
		String userID;
		String nickName=request.getParameter("nickName");
		String message=request.getParameter("message");
		ResultSet result;
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
			messages=new Vector();
		Calendar currentDate=Calendar.getInstance();
		String stringTime=currentDate.get(Calendar.HOUR_OF_DAY)+":"
			+currentDate.get(Calendar.MINUTE);
			
		messages.add("[<span class=\"comment\">"+stringTime
			+"</span> <span class=\"text\">"+nickName
			+"</span>] <span class=\"text1\">"+message+"</span>");
		if (messages.size()>MAX_MESSAGES)
			messages.removeElementAt(0);
		context.setAttribute("messages",messages);
		readFile("Web-inf/classes/templates/chat_message_template.html");
       	insertToken(buffer,0,"name=\"nickName\" value=\"",nickName);
		out.println(buffer);
	}
}