import java.io.*;
import java.net.*;
import java.util.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class startTest extends HttpServlet
{
	public void doPost(
		HttpServletRequest request,
		HttpServletResponse response) throws ServletException,IOException
	{
		String studentID=request.getParameter("studentID");
		String testID=request.getParameter("testID");
		String testTitle;
		String question;
		String choices[]=new String[5];
		int amount;
		int total_number;
		Statement statement;
		ResultSet result;
	
		try
		{
			Class.forName("com.mysql.jdbc.Driver").newInstance();
			String url = "jdbc:mysql://localhost:3306/eMarazm";
			Connection 	connection = DriverManager.getConnection(url,"root","");
			statement=connection.createStatement();
		
			statement.executeUpdate("insert ignore into grades values"+
				" ("+studentID+","+testID+",0,1,'0000-00-00 00:00:00',0.00)" );
		
		//	statement=connection.createStatement();
			result=statement.executeQuery("select * from tests where testID="+testID);
			result.absolute(1);
			testTitle=result.getString("testTitle");
	
		//	statement=connection.createStatement();
			result=statement.executeQuery("select count(*) from test"+testID);
			result.absolute(1);
			total_number=result.getInt("count(*)");
			
			result=statement.executeQuery("select * from test"+testID);
			result.absolute(1);
			question=result.getString("question");
			amount=result.getInt("amount");
			for (int i=0; i<amount; i++)
				choices[i]=new String(result.getString("choice"+
					Integer.toString(i+1)));
			connection.close();
			
		   	BufferedReader in=null;
        	StringBuffer buffer=new StringBuffer();
        	String line;
        
        	try
        	{
         		in=new BufferedReader(new FileReader(
        			getServletContext().getRealPath(
        				"/Web-inf/classes/templates/answer_one_template.html")));
        		while((line=in.readLine())!=null)
        			buffer.append(line+"\n");
        	}
        	finally
        	{
        		if (in != null)
        			in.close();  	
        	}			
        	response.setContentType("text/html");
			PrintWriter out=response.getWriter();
			
			int curPos=buffer.indexOf("</title>");
			buffer.insert(curPos,"Test "+testTitle);
			String token=new String("id=\"question_number\">");
			curPos=buffer.indexOf(token,curPos)+token.length();
			buffer.insert(curPos,"1");
			
			token="id=\"total_number\">";
			curPos=buffer.indexOf(token,curPos)+token.length();
			buffer.insert(curPos,Integer.toString(total_number));
		
			token="name=\"studentID\" value=\"";
			curPos=buffer.indexOf(token,curPos)+token.length();
			buffer.insert(curPos,studentID);
		
			token="name=\"testID\" value=\"";
			curPos=buffer.indexOf(token,curPos)+token.length();
			buffer.insert(curPos,testID);
		
			token="name=\"question\" value=\"";
			curPos=buffer.indexOf(token,curPos)+token.length();
			buffer.insert(curPos,"1");
		
			token="id=\"theDiv1\">";
			curPos=buffer.indexOf(token,curPos)+token.length();
			buffer.insert(curPos,question);
		
			int last=0;
			for (int i=0; i<amount; i++)
			{
				token="value=\"answer"+(i+1)+"\">";
				curPos=buffer.indexOf(token,curPos)+token.length();
				buffer.insert(curPos,choices[i]);
				last=i;
			}
		
			for (int i=last+2; i<=5; i++)
			{
				token="id=\"theDiv"+i+"\"";
				curPos=buffer.indexOf(token,curPos)+token.length();
				buffer.insert(curPos," style=\"display: none\"");
			}
			out.println(buffer);
		}
		catch (Exception exception)
		{
			exception.printStackTrace();
		}
	}
}