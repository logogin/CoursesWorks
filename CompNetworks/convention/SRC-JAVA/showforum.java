import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;//for sql servers...

public class showforum extends HttpServlet{
  public void doGet(HttpServletRequest req, 
                    HttpServletResponse res)
                      throws ServletException, IOException{
                        
 HttpSession   session = req.getSession(true);
 String str=(String)session.getValue("login");
 if(str!=null && str.equals("true"))
 {  			

    try {
      Statement stmt,stmt_tmp;//used for database access
      ResultSet resultSet,resultset_tmp;//used for database access

      //Set the content type of the data to be sent back
      // to the client.
      res.setContentType("text/html");
      
      //Get an output writer object to send data back to
      // the client.
      PrintWriter out = res.getWriter();
      
      //Begin constructing the HTML page to send back to
      // the client.
      out.println("<HTML>");
      out.println("<HEAD><TITLE=THE FORUM</TITLE></HEAD>");
      out.println("<BODY BGCOLOR=lightskyblue>");
      
      //Register the JDBC driver
      Class.forName("org.gjt.mm.mysql.Driver");  
      //Construct URL for database on localhost
      String url = "jdbc:mysql://localhost:3306/forum";
      //Get a connection to the database:  port/name of db...
      Connection con = DriverManager.getConnection(url,
                                         "",      ""); 
      //Get the incoming data parameters from the client
	  
	  String name = req.getParameter("name");
	  String headline = req.getParameter("headline");
      String message = req.getParameter("message");
 if(name!=null && headline !=null && message!=null)
  if (!(name.equals("")||headline.equals("")||message.equals("")))
   {
  //Use the statement object to execute a query on the
  // database.
  //Get a Statement object			no user  no psswd
    stmt = con.createStatement();
    resultSet = stmt.executeQuery(
      "SELECT  count(DISTINCT id) FROM forum_msg WHERE pid='0'");
    resultSet.next();
	Object obj1 = resultSet.getObject(1);
    int id=Integer.parseInt(obj1.toString())+1;
    out.println("<BR>HELLO"+name+obj1.toString()+"<BR>");
                                          
    stmt = con.createStatement();
      //Put the data into the database table. Don't forget
      // to enclose the string data in single quotes to 
      // satisfy the SQL syntax requirement.
    stmt.executeUpdate("INSERT INTO forum_msg "
                    + " VALUES('0','"//new headline= new pid...
                    + id + "','" 
					+ name + "','" 
                    + headline + "','" 
                    + message + "'"
                     + ")");
   }
      //start printing the database into the html forum
	  //Create a statement object linked to the database
      // connection.
      stmt = con.createStatement();

      //Use the statement object to execute a query on the
      // database.
      resultSet = stmt.executeQuery(
         "SELECT * from forum_msg WHERE PID='0'");

      out.println("<h1 ALIGN=\"CENTER\">THE FORUM</H1><BR><BR>");

      //Get info about the ResultSet
      ResultSetMetaData resultSetMetaData = 
                                   resultSet.getMetaData();
      int numColumns = resultSetMetaData.getColumnCount();
      
      //Start an output string that is an HTML table
      StringBuffer strBuf = new StringBuffer();
      //begin HTML table
      strBuf.append("<hr><br>");
      while(resultSet.next()) {
        strBuf.append("<hr><br>");
        for(int i = 1; i <= numColumns; i++){
          strBuf.append("<b>");
        Object obj = resultSet.getObject(i);
          strBuf.append(resultSetMetaData.getColumnLabel(i)
        		+"--></b>"+obj.toString()+"<br>");
        }//end for loop
        Object obj_tmp,obj = resultSet.getObject(2);
        stmt_tmp=con.createStatement();
      resultset_tmp=stmt_tmp.executeQuery(
         "SELECT * from forum_msg WHERE pid='"
       	+obj.toString()+"'");
      strBuf.append("<BR><b>Replies</b>.................................................");
      while(resultset_tmp.next()) {
            for(int i = 1; i <= numColumns; i++){
        		obj_tmp=resultset_tmp.getObject(i);
      		strBuf.append("<br>");
            	strBuf.append(resultSetMetaData.getColumnLabel(i)
          			+"-->"+obj_tmp.toString());
            }//end for loop
      }//end inner while
      }//end outer while		
      
	  strBuf.append("<br><center><form action=/convention/servlet/forumreply method=\"post\">") ;
	  strBuf.append("<br><a href=/convention/forum.html><b>go to home page<b><a>");
	  strBuf.append("<br><b>Reply to a main message</b>");
	  strBuf.append("<table>"+
                    "<tr>"   +
	                "<td>name</td>"+ 	  
	                "<td><INPUT TYPE=\"TEXT\" NAME=\"name\"><BR></td>"+
                    "</tr>"+
                    "<tr>"   +
                    "<td>id</td>"+ 	  
                    "<td><INPUT TYPE=\"TEXT\" NAME=\"id\"><BR></td>"+
                    "</tr>"+
                    "<tr>"+
	                "<td>headline</td>"+ 	  
	                "<td><INPUT TYPE=\"TEXT\" NAME=\"headline\"><BR></td>"+
                    "</tr>"+
                    "<tr>"+
	                "<td>message</td>"+	  
	                "<td><TEXTAREA NAME=\"message\" ROWS=3 COLS=40> </TEXTAREA><BR></td>"+
					"</tr>"+
                    "</table>"+
                    "<br> <INPUT TYPE=\"SUBMIT\" VALUE=\"Submit\">"+
                    "</FORM><center>");
	  out.println(strBuf);//send table to client

      //Finish the construction of the html page
	  out.println("</BODY></HTML>");
	  out.close();
      con.close();
    }catch( Exception e ) {
      e.printStackTrace();
    }//end catch
    }
    else res.sendRedirect("/convention/intro.html");
 
  }//end doGet()
    public void doPost(HttpServletRequest request,
                      HttpServletResponse response)
        throws IOException, ServletException
    {
        doGet(request, response);
    }
}//end class showforum
