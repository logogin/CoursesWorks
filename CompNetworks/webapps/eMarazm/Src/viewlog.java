import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class viewlog extends eMarazm
{
	public void doGet(
		HttpServletRequest request,
		HttpServletResponse response) throws ServletException,IOException
	{
		getHttpContext(request,response);
		String userID;
		int counter=0;
		ResultSet result;
		StringBuffer table=new StringBuffer();
		
		getWriter();
		response.setContentType("text/html");
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
			result=executeQuery("select * from logs order by entryDate DESC");
			while (result.next())
			{
				counter++;
				table.append("<tr><td align=\"right\" bgcolor=\"#EDEDEF\">"
					+Integer.toString(counter)+". </td>\n");
				table.append("<td bgcolor=\"#EDEDEF\">"+result.getString("entryDate")+"</td>\n");
				table.append("<td bgcolor=\"#EDEDEF\" class=\"comment\"><b>"
					+result.getString("message")+"</b></td></tr>\n");
			}
			
		}
		catch (SQLException sqlException)
		{
			sqlException.printStackTrace();
			sendRedirect(ERROR_PAGE);
			return;
		}
		readFile("Web-inf/classes/templates/logs_template.html");
		insertToken(buffer,0,"id=\"total\">",Integer.toString(counter));
		insertToken(buffer,0,"id=\"table\">",table.toString());
		out.println(buffer);
	}
	
}