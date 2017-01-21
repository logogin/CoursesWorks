import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class console extends eMarazm
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
		}
		catch (SQLException sqlException)
		{
			sqlException.printStackTrace();
			sendRedirect(ERROR_PAGE);
			return;
		}
		readFile("Web-inf/classes/templates/console_template.html");
		out.println(buffer);
	}
	
	public void doPost(
		HttpServletRequest request,
		HttpServletResponse response) throws ServletException,IOException
	{
		getHttpContext(request,response);
		String userID;
		String resultString;
		ResultSet result;
		StringBuffer resultTable=new StringBuffer();
		
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
		}
		catch (SQLException sqlException)
		{
			sqlException.printStackTrace();
			sendRedirect(ERROR_PAGE);
			return;
		}
		
		try
		{
			if ((statement=connection.createStatement()).execute(request.getParameter("statement")))
			{
				do
				{
					result=statement.getResultSet();
					ResultSetMetaData metaData=result.getMetaData();
					int columns=metaData.getColumnCount();
					StringBuffer table=new StringBuffer();
					table.append("<table cellpadding=\"6\" cellspacing=\"1\""
						+" border=\"0\" bgcolor=\"black\"><thead><tr>");
					for (int i=1; i<=columns; i++)
						table.append("<td class=\"thead\">"+metaData.getColumnLabel(i)+"</td>");
					table.append("</tr>");
					table.append("<tbody>");
					while (result.next())
					{
						table.append("<tr bgcolor=\"#F4F4F4\">");
						for (int i=1; i<=columns; i++)	
							table.append("<td>"+result.getString(i)+"</td>");
						table.append("</tr>");
					}	
					table.append("</table>");
					resultTable.append(table.toString()+"<br><br>");
				}
				while(statement.getMoreResults());
			}
			else
			{
				resultTable.append("<span class=\"text1\">"
					+statement.getUpdateCount()+"</span><span "
					+"class=\"comment\"><b> row(s) affected</b></span><br>");
			}
			
		}
		catch (SQLException sqlException)
		{
			SQLException exception=sqlException;
			do
			{
				exception.printStackTrace();
				resultTable.append("<span class=\"comment\"><b>"
					+exception.getMessage()+"</b></span><br><br>");
			}
			while ((exception=sqlException.getNextException())!=null);
		}
		readFile("Web-inf/classes/templates/console_template.html");
		insertToken(buffer,0,"name=\"statement\">",request.getParameter("statement"));
		insertToken(buffer,0,"id=\"result\">",resultTable.toString());
		out.println(buffer);
	}
}