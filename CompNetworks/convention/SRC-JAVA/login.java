import java.net.*;
import java.io.*;
import java.text.*;
import java.util.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class login extends HttpServlet {

    public void doGet(HttpServletRequest request,
                      HttpServletResponse response)
        throws IOException, ServletException
{

	
		response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        out.println("<html><head><title>MessageBoard</title></head>");
        out.println("<body bgcolor=lightskyblue>");
 	
        String usrname=request.getParameter("usrname");
        String psswd=request.getParameter("psswd");
	
   try
   { 
 	//Register the JDBC driver
 	Class.forName("org.gjt.mm.mysql.Driver");  
 	//Construct URL for database on localhost
 	String url = "jdbc:mysql://localhost:3306/forum";
 	//Get a connection to the database:  port/name of db...
 	Connection con = DriverManager.getConnection(url,"",""); 
 	Statement  stmt = con.createStatement();
    ResultSet resultSet = stmt.executeQuery(
    	  "SELECT  count(*) FROM participants where usrname='"
		 	+usrname+"' and psswd='"+psswd+"'");
    	resultSet.next();
    	Object obj1 = resultSet.getObject(1);
    	int num=Integer.parseInt(obj1.toString());
	stmt = con.createStatement();
	resultSet = stmt.executeQuery(
    	  "SELECT  count(*) FROM presenters where usrname='"
		 	+usrname+"' and psswd='"+psswd+"'");
    	resultSet.next();
    	obj1 = resultSet.getObject(1);
    	num+=Integer.parseInt(obj1.toString());
  	
	if(num>0)
		{	//start a session here...
		HttpSession   session = request.getSession(true);
		session.putValue("login",new String("true"));
		out.println("<h1>login correct-go ahead</h1>");
		}
   	else
   out.println("<h1>login incorrect-try again</h1>");
   con.close();
   
   }catch(Exception e)
   {out.println(e.toString()); 
   	e.printStackTrace();
   }
out.println("</body></html>");
out.close();
}
	    public void doPost(HttpServletRequest request,
                      HttpServletResponse response)
        throws IOException, ServletException
{
        doGet(request, response);
}

}//end class
