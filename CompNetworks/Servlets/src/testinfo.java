import java.io.*;
import java.net.*;
import java.util.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class testinfo extends HttpServlet
{
	public int insertToken(StringBuffer buffer,int curPos,String token,
		String string)
	{
		int result=buffer.indexOf(token,curPos)+token.length();
		buffer.insert(result,string);
		return result;
	}
	
	public void doGet(
		HttpServletRequest request,
		HttpServletResponse response) throws ServletException,IOException
	{
		String testID=request.getParameter("testID");
		String testTitle;
		String testTopicName;
		int testType;
		String testTopicID;
		java.sql.Date creationDate;
		String ownerID;
		String firstName;
		String lastName;
		
		StringBuffer buffer;
		int curPos;
		String line;
		BufferedReader in;
				
		PrintWriter out=response.getWriter();
		
		String url = "jdbc:mysql://localhost:3306/eMarazm";
		Connection connection;
		Statement statement;
		ResultSet result;
		
		response.setContentType("text/html");
			
		try
		{
			Class.forName("com.mysql.jdbc.Driver").newInstance();
		}
		catch (Exception exception)
		{
			exception.printStackTrace();
			response.sendRedirect("/eMarazm/error.html");
			return;	
		}
			
		try
		{
			connection = DriverManager.getConnection(url,"root","");
			statement=connection.createStatement();
			result=statement.executeQuery("select * from tests where testID='"
				+testID+"'");
			result.next();
			ownerID=result.getString("ownerID");
			testTopicID=result.getString("testTopicID");
			testTitle=result.getString("testTitle");
			testType=result.getInt("testType");
			creationDate=result.getDate("creationDate");
			
					
			statement=connection.createStatement();
			result=statement.executeQuery("select * from test_topics where"+
				" testTopicID='"+testTopicID+"'");
			result.next();
			testTopicName=result.getString("testTopicName");
			
			statement=connection.createStatement();
			result=statement.executeQuery("select * from users where userID='"
				+ownerID+"'");
			result.next();
			firstName=result.getString("firstName");
			lastName=result.getString("lastName");
		}
		catch (SQLException sqlException)
		{
			sqlException.printStackTrace();
			response.sendRedirect("/eMarazm/error.html");
			return;	
		}
		
		buffer=new StringBuffer();
		in=null;
		try
       	{
       		in=new BufferedReader(new FileReader(
       			getServletContext().getRealPath(
       				"Web-inf/classes/templates/test_info_template.html")));
       		while((line=in.readLine())!=null)
       			buffer.append(line+"\n");
       	}
       	finally
       	{
       		if (in != null)
       			in.close();  	
       	}
       	
       	curPos=insertToken(buffer,0,"id=\"testTitle\">",testTitle);
       	curPos=insertToken(buffer,curPos,"id=\"testTopicName\">",testTopicName);
       	if (testType==0)
       		curPos=insertToken(buffer,curPos,"id=\"testType\">",
       			"Single choice");
       	else
       		curPos=insertToken(buffer,curPos,"id=\"testType\">",
       			"Multiple choice");
       	curPos=insertToken(buffer,curPos,"servlet/info?userID=\"",
       		ownerID+"\" target=_blank title=\"Get info about \""
       		+firstName+" "+lastName+"\">"+firstName+" "+lastName);
       	curPos=insertToken(buffer,curPos,"id=\"creationDate\">",
       		creationDate.toString());
       	curPos=insertToken(buffer,curPos,"id=\"testDate\">","N/A");
       	curPos=insertToken(buffer,curPos,"id=\"grade\">","N/A");
       	
       	out.println(buffer);
	}
}