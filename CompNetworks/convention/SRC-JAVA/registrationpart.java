import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;//for sql servers...
//for participants...
public class registrationpart extends HttpServlet {
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
        String  cardType   = request.getParameter("cardType");
        String  cardNum    = request.getParameter("cardNum");
        String  usrname = request.getParameter("usrname");
        String  psswd   = request.getParameter("psswd");
        
		if (!(name.equals("") || email.equals("") || cardType.equals("")
			|| cardNum.equals("")||usrname.equals("")||psswd.equals("")))
		{
        try {

        //Register the JDBC driver
        Class.forName("org.gjt.mm.mysql.Driver");  
        //Construct URL for database on localhost
        String url = "jdbc:mysql://localhost:3306/forum";
        //Get a connection to the database:  port/name of db...
        Connection con = DriverManager.getConnection(url,"",""); 
        stmt = con.createStatement();
		stmt.executeUpdate("INSERT INTO participants "
                        + " VALUES('"//new headline= new pid...
                        + name + "','" 
        				+ email + "','" 
                        + cardType + "','"
						+ cardNum + "','"
						+ usrname + "','"
						+psswd 
						+ "')");
		HttpSession   session = request.getSession(true);
		session.putValue("login",new String("true"));
        out.println("<h2>A new participant has been added!!!</h2>");          
        //session code comes in here...
		con.close();
		
            }//end try 
			catch(Exception e) {
               e.printStackTrace();
            }
		}//end if
		else
		{ out.println("<h2>PLEASE FILL IN AGAIN YOUR REGISTRATION FORM!!!</h2>"); 
		}
		out.println("<P><A HREF=\"https://localhost:8443/convention/registrationpart.html\">Add another registration</A>");
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
