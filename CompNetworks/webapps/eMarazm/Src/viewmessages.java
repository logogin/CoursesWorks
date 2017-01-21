import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class viewmessages extends eMarazm
{
	public void doGet(
		HttpServletRequest request,
		HttpServletResponse response) throws ServletException,IOException
	{
		getHttpContext(request,response);
		String userID;
		String fromID;
		String messageID;
		String messageDate;
		String unRead;
		String firstName;
		String lastName;
		ResultSet result;
		int counter=0;
		
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
			result=executeQuery("select * from messages where toID='"+userID+"'");
			ResultSet userInfo;
			while (result.next())
			{
				messageID=result.getString("messageID");
				messageDate=result.getString("messageDate");
				if (result.getInt("unRead")==1)
					unRead="Unread";
				else
					unRead="Read";
				fromID=result.getString("fromID");
				userInfo=executeQuery("select * from users where userID='"+fromID+"'");
				userInfo.next();
				firstName=userInfo.getString("firstName");
				lastName=userInfo.getString("lastName");
				counter++;
				table.append("<tr><td align=\"right\" bgcolor=\"#EDEDEF\">"+counter+". </td>\n");
				table.append("<td bgcolor=\"#EDEDEF\"><a href=\"userinfo?userID="
					+fromID+"\" target=_blank title=\"Get info about "
       				+firstName+" "+lastName+"\">"+firstName+" "
       					+lastName+"</a></td>\n");
       			table.append("<td bgcolor=\"#EDEDEF\">"+messageDate+"</td>\n");
       			table.append("<td align=\"center\" class=\"comment\" bgcolor=\"#EDEDEF\"><b>"
       				+unRead+"</b></td>\n");
       			table.append("<td bgcolor=\"#EDEDEF\"><input type=\"button\" value=\"View\" onClick=\""
       				+"window.open('viewmessage?messageID="+messageID
       				+"','right')\"></td>\n");
       			table.append("<td bgcolor=\"#EDEDEF\"><input type=\"button\" value=\"Delete\" onClick=\""
       				+"window.open('deletemessage?messageID="+messageID
       				+"','right')\"></td></tr>\n");
			}
			
		}
		
		catch (SQLException sqlException)
		{
			sqlException.printStackTrace();
			sendRedirect(ERROR_PAGE);
			return;
		}
		
		readFile("Web-inf/classes/templates/messages_list_template.html");
		
		insertToken(buffer,0,"id=\"total\">",Integer.toString(counter));
		insertToken(buffer,0,"id=\"messages\">",table.toString());
		
		out.println(buffer);
	}
}	
