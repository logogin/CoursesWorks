import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class showtree extends eMarazm
{
	public void doGet(
		HttpServletRequest request,
		HttpServletResponse response) throws ServletException,IOException
	{
		getHttpContext(request,response);
		ResultSet result;
		
		setContentType("text/html");
		getWriter();
		if (getSession(false)==null)
		{
			sendRedirect(INDEX_PAGE);
			return;
		}		
		if (session.getAttribute("userID")==null)
		{
			sendRedirect(ERROR_PAGE);
			return;
		}
		
		connectDataBase();
		
		StringBuffer branches=new StringBuffer();
		try
		{
			result=executeQuery("select * from test_topics");
			
			while(result.next())    
	        {
	        	String testTopicID=result.getString("testTopicID");
	        	String testTopicName=result.getString("testTopicName");
	        	branches.append("<div class=\"trigger\""+
	        		" onClick=\"showBranch('"+formatString(testTopicName)+"');"+
	        		" swapFolder('img_topic"+testTopicID+"')\">");
	    	    	branches.append("<img src=\"/eMarazm/Images/TreeIcons/closed.gif\""+
	        		" border=\"0\" id=\"img_topic"+formatString(testTopicID)+"\">"
	        		+testTopicName+"</div>");
	        	branches.append("<span class=\"branch\" id=\""
	        		+testTopicName+"\">");
	        		
	           	ResultSet tests;
	           	tests=executeQuery("select * from tests where "+
	        		"testTopicID='"+testTopicID+"'");
	        	while (tests.next())	
	        	{
	        		String testID=tests.getString("testID");
	        		String testTitle=tests.getString("testTitle");
	        		
	        		branches.append("<img src=\"/eMarazm/Images/TreeIcons/doc.gif\""+
	        			" border=\"0\"><a href=\"testinfo?testID="
	        			+testID+"\" target=\"right\">"+testTitle+"</a><br>");
	        	}
	           	branches.append("</span>");
	        }
		}
		
		catch (SQLException sqlException)
		{
			sqlException.printStackTrace();
			sendRedirect(ERROR_PAGE);
			return;
		}
		
		readFile("Web-inf/classes/templates/tree_template.html");
       	
       	insertToken(buffer,0,"id=\"topics\">",branches.toString());
       	
       	out.println(buffer);
	}	
}