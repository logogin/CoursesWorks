import java.io.*;
import java.net.*;
import java.util.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class register extends HttpServlet
{
	public void doPost(
		HttpServletRequest request,
		HttpServletResponse response) throws ServletException,IOException
		
	{
		String userID=request.getParameter("userID");
		String password=request.getParameter("password");
		String firstName=request.getParameter("firstName");
		String lastName=request.getParameter("lastName");
		String email=request.getParameter("email");
		String publicData=request.getParameter("publicData");
		
		response.setContentType("text/html");
		
		Statement statement;
		ResultSet result;

		String url = "jdbc:mysql://localhost:3306/eMarazm";
		Connection 	connection;

		try
		{				
			Class.forName("com.mysql.jdbc.Driver").newInstance();
		}
		catch (Exception exception)
		{
			exception.printStackTrace();
			return;	
		}
	
		try
		{
			connection = DriverManager.getConnection(url,"root","");
		
			statement=connection.createStatement();
			statement.executeUpdate("insert into users values"+
				" ('"+userID+"','"+password+"','student','"+firstName+"','"
				+lastName+"','"+email+"','"+publicData+"')");
		}
		
		catch (SQLException sqlException)
		{
			sqlException.printStackTrace();
			response.sendRedirect("http://localhost:8080/BadLogin.html");
			return;
		}
		
		BufferedReader in=null;
        StringBuffer buffer=new StringBuffer();
        String line;
        
        try
        {
        	in=new BufferedReader(new FileReader(
        		getServletContext().getRealPath(
        			"/Web-inf/classes/templates/do_login_template.html")));
        	while((line=in.readLine())!=null)
        			buffer.append(line+"\n");
        }
        
        finally
        {
        	if (in != null)
        		in.close();  	
        }			
        
        PrintWriter out=response.getWriter();
			
		int curPos=buffer.indexOf("</title>");
       	buffer.insert(curPos,"Wellcome !!!");
        	
		String token=new String("id=\"firstName\">");
		curPos=buffer.indexOf(token,curPos)+token.length();
		buffer.insert(curPos,firstName);
			
		token=new String("id=\"lastName\">");
		curPos=buffer.indexOf(token,curPos)+token.length();
		buffer.insert(curPos,lastName);
      	
		out.println(buffer);
	}
}