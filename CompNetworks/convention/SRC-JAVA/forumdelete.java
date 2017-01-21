import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;//for sql servers...

public class forumdelete extends HttpServlet{
  public void doGet(HttpServletRequest req, 
                    HttpServletResponse res)
                      throws ServletException, IOException{
                        
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
      out.println("<HEAD><TITLE=\"UPDATE THE FORUM\"</TITLE></HEAD>");
      out.println("<BODY BGCOLOR=lightskyblue>");
      
      //Register the JDBC driver
      Class.forName("org.gjt.mm.mysql.Driver");  
      //Construct URL for database on localhost
      String url = "jdbc:mysql://localhost:3306/forum";
      //Get a connection to the database:  port/name of db...
      Connection con = DriverManager.getConnection(url,
                                         "",      ""); 
      //Get the incoming data parameters from the client
	  String pid = req.getParameter("pid");
	  String id = req.getParameter("id");
 if(pid!=null && id !=null)
  if (!(pid.equals("")||id.equals("")))
   {
  //Use the statement object to execute a query on the
  // database.
  //Get a Statement object			
	stmt = con.createStatement();
    stmt.executeUpdate("DELETE FROM forum_msg "
                    + " WHERE pid='"+pid+"'	AND id='"//new headline= new pid...
                    + id + "'");
    if(pid.equals("0"))
        	stmt.executeUpdate("DELETE FROM forum_msg "
               	 	+ " WHERE pid='"+id+"'");
		
   }
   //start printing the database into the html forum
   //Create a statement object linked to the database
   // connection.
   stmt = con.createStatement();

   //Use the statement object to execute a query on the
   // database.
   resultSet = stmt.executeQuery(
      "SELECT * from forum_msg WHERE PID='0'");

   out.println("<h1 ALIGN=\"CENTER\">THE FORUM-administrator's page</H1><BR><BR>");

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
   
   strBuf.append("<br><center><form action=/convention/servlet/forumdelete method=\"post\">") ;
   strBuf.append("<br><a href=/convention/forum.html><b>go to forum home page<b><a>");
   strBuf.append("<br>Enter pid and id of message you want to delete<br>") ;
   strBuf.append("<table>"+
                 "<tr>"   +
                 "<td>pid of message</td>"+ 	  
                 "<td><INPUT TYPE=\"TEXT\" NAME=\"pid\"><BR></td>"+
                 "</tr>"+
                 "<tr>"   +
                 "<td>id of message</td>"+ 	  
                 "<td><INPUT TYPE=\"TEXT\" NAME=\"id\"><BR></td>"+
                 "</tr>"+
                 "</table>"+
                 "<br> <INPUT TYPE=\"SUBMIT\" VALUE=\"Delete\">"+
                 "</FORM><center>");
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
}//end class delete
