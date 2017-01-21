import java.io.*;
import java.util.*;
import javax.servlet.*;
import javax.servlet.http.*;
import javax.mail.*;
import javax.mail.internet.*;
import java.sql.*;

public class sendmail extends eMarazm
{
	public void doGet(
		HttpServletRequest request,
		HttpServletResponse response) throws ServletException,IOException
	{
		getHttpContext(request,response);
		String userID;
		String firstName;
		String lastName;
		String toAddress;
		String fromAddress;
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
		connectDataBase();
		try
		{
			result=executeQuery("select * from users where userID='"+toID+"'");
			result.next();
			firstName=result.getString("firstName");
			lastName=result.getString("lastName");
			toAddress=result.getString("email");
			result=executeQuery("select * from users where userID='"+userID+"'");
			result.next();
			fromAddress=result.getString("email");
		}
		
		catch (SQLException sqlException)
		{
			sqlException.printStackTrace();
			sendRedirect(ERROR_PAGE);
			return;
		}
		
		readFile("Web-inf/classes/templates/send_mail_template.html");
		
		insertToken(buffer,0,"id=\"toName\">",firstName+" "+lastName);
		insertToken(buffer,0,"name=\"toAddress\" value=\"",toAddress);
		insertToken(buffer,0,"name=\"fromAddress\" value=\"",fromAddress);
		
		out.println(buffer);
	}
	
	public void doPost(
		HttpServletRequest request,
		HttpServletResponse response) throws ServletException,IOException
	{
		getHttpContext(request,response);
		String userID;
		String toAddress=request.getParameter("toAddress");
		String fromAddress=request.getParameter("fromAddress");
		String ccAddress=request.getParameter("ccAddress");
		String smtpHost=getInitParameter("smtpHost");
		if (ccAddress==null)
			ccAddress="";
		String subject=request.getParameter("subject");
		if (subject==null)
			subject="";
		String message=request.getParameter("message");
		if (message==null)
			message="";
		String smptHost=getInitParameter("smptHost");
		
		getWriter();
		setContentType("text/html");
		ResultSet result;
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
		
		Properties properties = new Properties();
		properties.put("mail.host",smtpHost);
		try
		{
			Session mailConnection = Session.getInstance(properties,null);
			Message msg = new MimeMessage(mailConnection);
			msg.setContent(message,"text/plain");
			msg.setFrom(new InternetAddress(fromAddress));
			msg.setRecipient(Message.RecipientType.TO,new InternetAddress(toAddress));
			if (!ccAddress.equals(""))
				msg.setRecipient(Message.RecipientType.CC,new InternetAddress(ccAddress));
			msg.setSubject(subject);
			Transport.send(msg);
		}
		
		catch (MessagingException messagingException)
		{
			messagingException.printStackTrace();
			sendRedirect(ERROR_PAGE);
			return;
		}
	
		sendRedirect(SENT_PAGE);
	}
}