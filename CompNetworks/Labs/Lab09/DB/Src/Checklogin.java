
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class Checklogin extends HttpServlet {

  public void doGet(HttpServletRequest request,
                    HttpServletResponse response)
      throws IOException, ServletException
{

      if (check(request))

          response.sendRedirect( "http://localhost:8080\\DB\\goodlogin.html");

         else
           response.sendRedirect("http://localhost:8080\\DB\\badlogin.html");


}

     public void doPost(HttpServletRequest request,
                    HttpServletResponse response)
      throws IOException, ServletException
{
      doGet(request, response);
}


//Check method: checks the existence of the given username and password
public boolean check(HttpServletRequest req)
{
	String username = (String)req.getParameter("username");
 	String pass = (String)req.getParameter("pass");

	try
	{
          Class.forName("org.gjt.mm.mysql.Driver");
          String url = "jdbc:mysql://localhost:3306/password";
          Connection con = DriverManager.getConnection(url,"", "");
          Statement  stmt = con.createStatement();
          ResultSet   resultSet = stmt.executeQuery(
              "SELECT * FROM user_passwords where username='"+username+"'"+
              " and password='"+pass+"';");
          return resultSet.first() ;

	}
        catch ( Exception e)
        {
          return false;

        }

}

}//end class
