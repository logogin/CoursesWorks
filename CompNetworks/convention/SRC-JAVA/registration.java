import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;//for sql servers...
//for presenters...
public class registration extends HttpServlet {
    public void doGet(HttpServletRequest request,
                        HttpServletResponse response)
                        throws ServletException, IOException
   {
        
		
   		Statement stmt,stmt_tmp;//used for database access
		response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        out.println("<body BGCOLOR=lightskyblue>");
        String name = request.getParameter("name");
		String email = request.getParameter("email");
        String subject = request.getParameter("subject");
        String link = request.getParameter("link");
        String notes = request.getParameter("notes");
        String  usrname = request.getParameter("usrname");
        String  psswd   = request.getParameter("psswd");
        
		if (!(name.equals("") || email.equals("") || subject.equals("")
			|| link.equals("")||usrname.equals("")||psswd.equals("")))
		{
        try {

        //Register the JDBC driver
        Class.forName("org.gjt.mm.mysql.Driver");  
        //Construct URL for database on localhost
        String url = "jdbc:mysql://localhost:3306/forum";
        //Get a connection to the database:  port/name of db...
        Connection con = DriverManager.getConnection(url,"",""); 
        stmt = con.createStatement();
		stmt.executeUpdate("INSERT INTO presenters "
                        + " VALUES('"//new headline= new pid...
                        + name + "','" 
        				+ email + "','" 
                        + subject + "','"
                        + link + "','"
						+ notes + "','"
						+ usrname + "','"
						+ psswd 
						+ "')");
		HttpSession   session = request.getSession(true);
		session.putValue("login",new String("true"));
        
		out.println("<h2>A new presenter has been added!!!</h2>");          
        con.close();
		//add here session code...
            }//end try 
			catch(Exception e) {
               e.printStackTrace();
            }
		}//end if
		else
		{ out.println("<h2>PLEASE FILL IN AGAIN YOUR REGISTRATION FORM!!!</h2>"); 
		}
		out.println("<P><A HREF=\"https://localhost:8443/convention/registration.html\">Add another registration</A>");
		out.println("<P><A HREF=\"http://localhost:8080/convention/servlet/articles\">View participating articles</A>");		
		out.close();
   }//end doGet
   public void doPost(HttpServletRequest request,
                     HttpServletResponse response)
       throws IOException, ServletException
   {
       doGet(request, response);
   }
}//end class 
