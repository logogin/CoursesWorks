
import javax.mail.*;
import javax.mail.internet.*;

import java.io.*;

import java.util.*;
import javax.servlet.*;
import javax.servlet.http.*;


public class Sendmail extends HttpServlet {

public boolean checkErrors(Hashtable param)
{
if(((String)param.get("To")).equals(""))
return false;
if(((String)param.get("From")).equals(""))
return false;
if(((String)param.get("smtphost")).equals(""))
return false;
return true;
}


public void Send(Hashtable param)
{
try
{
Address ccAddress;	
Properties props = new Properties();
props.put("mail.host",((String) param.get("smtphost")));
Session mailConnection = Session.getInstance(props,null);
Message msg = new MimeMessage(mailConnection);
Address toAddress = new InternetAddress((String) param.get("To"));
String cc = (String) param.get("CC");
Address fromAddress = new InternetAddress((String) param.get("From"));

msg.setContent(((String) param.get("textbody")),((String) param.get("contenttype")));
msg.setFrom(fromAddress);
msg.setRecipient(Message.RecipientType.TO,toAddress);
if (!cc.equals(""))
{
ccAddress = new InternetAddress(cc);
msg.setRecipient(Message.RecipientType.CC,ccAddress);
}
msg.setSubject((String)param.get("subject"));
Transport.send(msg);
}
catch (Exception e)
{
e.printStackTrace();
}
}



public void doGet(HttpServletRequest request,
                      HttpServletResponse response)
        throws IOException, ServletException
    {

        response.setContentType("text/html");

        PrintWriter out = response.getWriter();
        out.println("<html>");
        out.println("<body>");
        out.println("<head>");
        out.println("</head>");
        out.println("<body bgcolor=\"white\">");
//put html param values into a hashtable for checking...
Enumeration paramNames=request.getParameterNames();
Hashtable mailProperties = new Hashtable();
while (paramNames.hasMoreElements())
{
	String paramName=(String)paramNames.nextElement();
	String[] paramValue = request.getParameterValues(paramName);
	mailProperties.put(paramName,paramValue[0]);
   
    }
	if (checkErrors(mailProperties))
	{
	Send(mailProperties);
	out.println("<h1>Your Message was delivered</H1></BODY></HTML>");
	}
	else
		out.println("<h1>There was an error with your form</h1></body></html>");
    }	    
	
public void doPost(HttpServletRequest request,
                   HttpServletResponse response)
        throws IOException, ServletException
    {
        doGet(request, response);
    }

}
