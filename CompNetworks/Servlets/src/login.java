import java.io.*;
import java.net.*;
import java.util.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class login extends HttpServlet
{
	public void doPost(
		HttpServletRequest request,
		HttpServletResponse response) throws ServletException,IOException
	{
		String userID=request.getParameter("userID");
		String password=request.getParameter("password");
		Statement statement;
		ResultSet result;
		
		PrintWriter out=response.getWriter();
		
		String firstName;
		String lastName;
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
		
		String url = "jdbc:mysql://localhost:3306/eMarazm";
		Connection connection;
		
		try
		{
			connection = DriverManager.getConnection(url,"root","");
			statement=connection.createStatement();
			result=statement.executeQuery("select * from users where userID='"
				+userID+"' and password='"+password+"'");
				
			result.next();/*!!!!!!!!!!!!!!!*/
			firstName=result.getString("firstName");
			lastName=result.getString("lastName");
		}
			
		catch(SQLException sqlException)
		{
			sqlException.printStackTrace();
			response.sendRedirect( "/eMarazm/badlogin.html");
			return;
		}
		
        StringBuffer buffer=new StringBuffer();
        BufferedReader in=null;
        String line;
       	
       	int curPos;
		
		
		//out.println("Here");		
		try
       	{
       		in=new BufferedReader(new FileReader(
       			getServletContext().getRealPath(
       				"Web-inf/classes/templates/tree_template.html")));
       		while((line=in.readLine())!=null)
       			buffer.append(line+"\n");
       	}
       	finally
       	{
       		if (in != null)
       			in.close();  	
       	}
       	StringBuffer branches=new StringBuffer();
       	
       	try
       	{
       	/*	statement=connection.createStatement();
       		result=statement.executeQuery("select count(*) from test_topics");
       		result.next();
	        int rowcount = result.getInt(1);*/
	        
	        statement=connection.createStatement();
	        result=statement.executeQuery("select * from test_topics");
	        
	        while(result.next())    
	        //for (int i=1; i<=rowcount; i++)
	        {
	        //	result.next();
	        	String testTopicID=result.getString("testTopicID");
	        	String testTopicName=result.getString("testTopicName");
	        	branches.append("<div class=\"trigger\""+
	        		" onClick=\"showBranch('"+testTopicName+"');"+
	        		" swapFolder('img_topic"+testTopicID+"')\">");
	    	    	branches.append("<img src=\"./Images/TreeIcons/closed.gif\""+
	        		" border=\"0\" id=\"img_topic"+testTopicID+"\">"
	        		+testTopicName+"</div>");
	        	branches.append("<span class=\"branch\" id=\""
	        		+testTopicName+"\">");
	        		
	        //	out.println(branches);	
	        	
	        /*	statement=connection.createStatement();	
	        	ResultSet tests=statement.executeQuery("select count(*) from"+
	        		" tests where testTopicID="+testTopicID);
	        	tests.next();
	        	int testsrows=tests.getInt(1);*/
	        	ResultSet tests;
	        	statement=connection.createStatement();
	        	tests=statement.executeQuery("select * from tests where "+
	        		"testTopicID='"+testTopicID+"'");
	        	while (tests.next())	
	        	//for (int j=1; j<=testsrows; j++)
	        	{
	        	//	tests.next();
	        		String testID=tests.getString("testID");
	        		String testTitle=tests.getString("testTitle");
	        		
	        		branches.append("<img src=\"./Images/TreeIcons/doc.gif\""+
	        			" border=\"0\"><a href=\"servlet/testinfo?testID=\""
	        			+testID+" target=\"right\">"+testTitle+"</a><br>");
	        	}
	        	
	        	branches.append("</span>");
	        }

       		
       	}
       	catch(SQLException sqlException)
       	{
       		sqlException.printStackTrace();
       		response.sendRedirect("/eMarazm/error.html");
       		return;
       	}
       	
       	curPos=insertToken(buffer,0,"id=\"topics\">",branches.toString());
          	
       	FileWriter file=null;
       	try
       	{
       		file=new FileWriter(new File(
       			getServletContext().getRealPath("/left_tree.html")));
       		file.write(buffer.toString());
       	}
       	finally
       	{
       		if (file!=null)	
       			file.close();
       	}
       	
       	buffer=new StringBuffer();
       	try
       	{
       		in=new BufferedReader(new FileReader(
       			getServletContext().getRealPath(
       				"Web-inf/classes/templates/main_template.html")));
       		while((line=in.readLine())!=null)
       			buffer.append(line+"\n");
       	}
       	finally
       	{
       		if (in != null)
       			in.close();  	
       	}
       	
       	
       	insertToken(buffer,0,"name=\"left\" src=\"","./left_tree.html");
       	insertToken(buffer,0,"name=\"right\" src=\"","./right_wellcome.html");
       	
       	file=null;
       	try
       	{
       		file=new FileWriter(new File(
       			getServletContext().getRealPath("/main.html")));
       		file.write(buffer.toString());
       	}
       	
       	finally
       	{
       		if (file!=null)
       			file.close();
       	}
       	
       	buffer=new StringBuffer();
       	
       	try
       	{
       		in=new BufferedReader(new FileReader(
       			getServletContext().getRealPath(
       				"Web-inf/classes/templates/do_login_template.html")));
       		while((line=in.readLine())!=null)
       			buffer.append(line+"\n");
       	}
       	finally
       	{
       		if (in != null)
       			in.close();  	
       	}
       	
       	
       	curPos=insertToken(buffer,0,"<title>","Wellcome !!!");
    	curPos=insertToken(buffer,curPos,"id=\"firstName\">",firstName);
		curPos=insertToken(buffer,curPos,"id=\"lastName\">",lastName);
		
		file=null;
       	try
       	{
       		file=new FileWriter(new File(
       			getServletContext().getRealPath("/right_wellcome.html")));
       		file.write(buffer.toString());
       	}
       	
       	finally
       	{
       		if (file!=null)
       			file.close();
       	}
		
		response.sendRedirect("/eMarazm/main.html");
	}
	
	public int insertToken(StringBuffer buffer,int curPos,String token,
		String string)
	{
		int result=buffer.indexOf(token,curPos)+token.length();
		buffer.insert(result,string);
		return result;
	}
}