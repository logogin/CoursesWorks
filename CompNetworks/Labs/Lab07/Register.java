//   Register.java
//

//The primary purpose of this program is to illustrate the
//use of the JDBC ResultSetMetaData interface, which provides
//a way to get information about the underlying structure of
//a ResultSet object at runtime.

//This servlet performs a query on a database and then 
//displays the resulting table in an HTML table without 
//knowing anything about the contents of the ResultSet object
//in advance.



//This servlet performs the following operations:
//1. Use a servlet to get data from a client form.
//2, Use the servlet to access a database to store
//   data obtained from the client form.
//3. Use the servlet to access the database to retrieve
//   data.
//4. Use the servlet to automatically format the data 
//  into an HTML table and send it back to the client.

//The program was tested using three computers on the 
//network, all running JDK 1.2 under Win95.
//-------
//For this test, the HTTP server program from JavaSoft 
//named Java Web Server 1.1.1 was running on one machine.
//
//The database server program named mSQL was running on a 
//second machine.
//-------
// we  use  the  HTTP server
//Tomcat-Apache
// and  DataBaseServer
//MyQSQL


//An HTML file containing five fields and one submit button
//was loaded into the browser.  The five fields were:
  

//The servlet was activated by the following tag in the
//HTML file.

//FORM METHOD=GET 
//ACTION="http://localhost:8080/servlet/Register">

//This tag caused a GET request to be sent to the server and
//caused the server to call the servlet named Servlet05. The
//request from the client was handled by an overridden
//doGet() method in the servlet.

//The servlet got a connection to a specified database
//server on the machine named localhost using the following URL:
  
//jdbc:mysql://localhost:3306/test

//Then, the code in the servlet obtained the value of the
//parameter named clear from the client.  If the value was
//either Y or y, and a table named Participants already
//existed, it was deleted.

//Next, the servlet created a new table named Participants
//if a table of that name didn't already exist

//The servlet then got the values for the parameters named
//firstName, middleInitial, and lastName from the client and 
//inserted them into the database table.

//After this, the servlet 
//- Accessed the database server and got a ResultSet table
// containing all of the data in the database
//- Used ResultSetMetaData to get information about the 
//ResultSet table
//- Used that information to format the data in the ResultSet
// table into an HTML table and returned the HTML table to
//  the browser where it appeared in the browser window.

//The program was also successfully tested using the JavaSoft
//servletrunner program running on localhost as a substitute
//for the HTTP server.  In this case, only two different
//machines were involved:  one for the browser and 
//servletrunner and one for the database server.
//**********************************************************/
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;//for sql servers...

public class Register extends HttpServlet{
  public void doGet(HttpServletRequest req, 
                    HttpServletResponse res)
                      throws ServletException, IOException{
                        
    try {
      Statement stmt;//used for database access
      ResultSet resultSet;//used for database access

      //Set the content type of the data to be sent back
      // to the client.
      res.setContentType("text/html");
      
      //Get an output writer object to send data back to
      // the client.
      PrintWriter out = res.getWriter();
      
      //Begin constructing the HTML page to send back to
      // the client.
      out.println("<HTML>");
      out.println("<HEAD><TITLE=Register</TITLE></HEAD>");
      out.println("<BODY>");
      
      //Register the JDBC driver
      Class.forName("org.gjt.mm.mysql.Driver");  
      //Construct URL for database on localhost
      String url = "jdbc:mysql://localhost:3306/test";
      //Get a connection to the database:  port/name of db...
      Connection con = DriverManager.getConnection(url,
                                           "",      ""); 
      //Get a Statement object			no user  no psswd
      stmt = con.createStatement();
     
	
      
      //Get the incoming data parameters from the client
	  String userName = req.getParameter("userName");
	  String password = req.getParameter("password");
      String firstName = req.getParameter("firstName");
	  String lastName = req.getParameter("lastName");
      String eMail = req.getParameter("eMail");
                                          
      
        
      //Put the data into the database table. Don't forget
      // to enclose the string data in single quotes to 
      // satisfy the SQL syntax requirement.
      stmt.executeUpdate("INSERT INTO Participants ("
                    + "userName,password,firstName,lastName,eMail)"
                    + " VALUES('" 
                    + userName + "','" 
					+ password + "','" 
					+ firstName + "','" 
                    + lastName + "','" 
                    + eMail + "'"
                    + ")");
      
      //Create a statement object linked to the database
      // connection.
      stmt = con.createStatement();

      //Use the statement object to execute a query on the
      // database.
      resultSet = stmt.executeQuery(
         "SELECT * from Participants");

      out.println("List of registered participants <BR><BR>");

      //Get info about the ResultSet
      ResultSetMetaData resultSetMetaData = 
                                   resultSet.getMetaData();
      int numColumns = resultSetMetaData.getColumnCount();
      
      //Start an output string that is an HTML table
      StringBuffer strBuf = new StringBuffer();
      //begin HTML table
      strBuf.append("<TABLE BORDER=2>\n");
      
      //Use column labels from ResultSet for table titles
      strBuf.append("<TR>");//table row tag
      for(int i = 1; i <= numColumns; i++){
        strBuf.append("<TH>"//table header element tag
                    + resultSetMetaData.getColumnLabel(i));
      }//end for loop
      strBuf.append("</TR>\n");//end table row
      
      while(resultSet.next()) {
        strBuf.append("<TR>");//new row
        for(int i = 1; i <= numColumns; i++){
          strBuf.append("<TD>");//table data element tag
          Object obj = resultSet.getObject(i);
          if(obj != null){
            strBuf.append(obj.toString());
          }//end if(obj != null)
          else{
            strBuf.append("&nbsp;");//non-breaking space
          }//end else
        }//end for loop
        strBuf.append("</TR>");//end table row
      }//end while loop
      strBuf.append("</TABLE>");//end table
      
      out.println(strBuf);//send table to client

      //Finish the construction of the html page
      out.println("</BODY></HTML>");
	  
      con.close();
    }catch( Exception e ) {
      e.printStackTrace();
    }//end catch
  }//end doGet()
    public void doPost(HttpServletRequest request,
                      HttpServletResponse response)
        throws IOException, ServletException
    {
        doGet(request, response);
    }
}//end class Register
