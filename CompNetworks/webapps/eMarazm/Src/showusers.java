import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class showusers extends eMarazm
{
	public void doGet(
		HttpServletRequest request,
		HttpServletResponse response) throws ServletException,IOException
	{
		getHttpContext(request,response);
		String userID;
		String firstName;
		String lastName;
		String group;
		int counter=0;
		ResultSet result;
		StringBuffer table=new StringBuffer();
		
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
			result=executeQuery("select * from users where userID='"+userID+"'");
			result.next();
			group=result.getString("_group");
			if (isGroup(group,ADMIN_GROUP))
				result=executeQuery("select * from users");
			else
				result=executeQuery("select * from users where publicData='1'");
			while (result.next())
			{
				counter++;
				userID=result.getString("userID");
				firstName=result.getString("firstName");
				lastName=result.getString("lastName");
				group=result.getString("_group");
				table.append("<tr><td align=\"right\""
					+" bgcolor=\"#EDEDEF\">"+counter+". </td>\n");
				table.append("<td bgcolor=\"#EDEDEF\"><a href=\"userinfo?userID="+userID
					+"\" target=_blank title=\"Get info about "
       				+firstName+" "+lastName+"\">"+firstName+" "+lastName+"</a></td>\n");
       			table.append("<td bgcolor=\"#EDEDEF\"> "+getGroupString(group)+"</td></tr>\n");
			}
		}
		catch (SQLException sqlException)
		{
			sqlException.printStackTrace();
			sendRedirect(ERROR_PAGE);
			return;	
		}
		readFile("Web-inf/classes/templates/show_users_template.html");
		insertToken(buffer,0,"id=\"total\">",Integer.toString(counter));
		insertToken(buffer,0,"id=\"table\">",table.toString());
		out.println(buffer);
	}
}