import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;//for sql servers...

public class AddMessage extends HttpServlet {
    public void doGet(HttpServletRequest request,
                        HttpServletResponse response)
                        throws ServletException, IOException
   {
        
   	HttpSession   session = request.getSession(true);
   	String str=(String)session.getValue("login");
	if(str!=null && str.equals("true"))
	{  			
		Statement stmt;//used for database access
		response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        out.println("<body bgcolor=lightskyblue>");
        String name = request.getParameter("name");
		String email = request.getParameter("email");
        String newmsg = request.getParameter("newmsg");
        if (!(name.equals("") || email.equals("") || newmsg.equals("")))
		{
        try {

        //Register the JDBC driver
        Class.forName("org.gjt.mm.mysql.Driver");  
        //Construct URL for database on localhost
        String url = "jdbc:mysql://localhost:3306/forum";
        //Get a connection to the database:  port/name of db...
        Connection con = DriverManager.getConnection(url,"",""); 
        stmt = con.createStatement();
        stmt.executeUpdate("INSERT INTO msgboard "
                        + " VALUES('"//new headline= new pid...
                        + name + "','" 
        				+ email + "','" 
                        + newmsg + "'"
                        + ")");
        out.println("<h2>new message has been added!!!</h2>");          
        con.close();
		
            }//end try 
			catch(Exception e) {
               e.printStackTrace();
            }
		}//end if
		else
		{ out.println("<h2>Please enter an adequate message!!!</h2>"); 
		}
		out.println("<P><A HREF=/convention/AddMessage.html>Add another message</A>");
		out.println("<P><A HREF=/convention/servlet/MessageBoard>View messages</A>");		
		out.close();
   
	}
	else response.sendRedirect("/convention/intro.html");
   }//end doGet
   public void doPost(HttpServletRequest request,
                     HttpServletResponse response)
       throws IOException, ServletException
   {
       doGet(request, response);
   }
}//end class 
