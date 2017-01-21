import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.util.*;
import java.sql.*;//for sql servers...

public class articles extends HttpServlet {
    public void doGet(HttpServletRequest request,
                        HttpServletResponse response)
                        throws ServletException, IOException
  {
        
  
HttpSession   session = request.getSession(true);
String str=(String)session.getValue("login");
if(str!=null && str.equals("true"))
{  			
   	
	Statement stmt;//used for database access
   	ResultSet resultSet;//used for database access
	response.setContentType("text/html");
    PrintWriter out = response.getWriter();
    out.println("<html><head><title>articles participating in the convention</title></head><body>");
    out.println("<body bgcolor=lightskyblue>");
    out.println("<h1>articles participating in the convention</h1>");
    try{
    	//Register the JDBC driver
    	Class.forName("org.gjt.mm.mysql.Driver");  
    	//Construct URL for database on localhost
    	String url = "jdbc:mysql://localhost:3306/forum";
    	//Get a connection to the database:  port/name of db...
    	Connection con = DriverManager.getConnection(url,"",""); 
    	stmt = con.createStatement();
    	resultSet = stmt.executeQuery("SELECT * from presenters");
    	StringBuffer strBuf = new StringBuffer();
		while(resultSet.next()) {
			strBuf.append("<hr><br><b>presenter:</b>"
						  +"<a href=\" mailto:"
						  +(resultSet.getObject(2)).toString()
						  +"\">"
						  +(resultSet.getObject(1)).toString()
						  +"</a>"
						  +"<br><b>article:</b>"
		     			  +"<a href=\"http://"
						  +(resultSet.getObject(4)).toString()
						  +"\">"+(resultSet.getObject(3)).toString()+"</a>"
						  +"<br><b>author's notes:</b>"
						  +(resultSet.getObject(5)).toString());
		}//end while...	
	/*	strBuf.append("<hr><h2>mail someone</h2><br>"
			+"<P>&nbsp</P><P Align=Center>"
			+"<FORM method=post action=/convention/servlet/Sendmail>"
			+"<table cellspacing=0  bgcolor=lightskyblue width=\"300\" cellpadding=3 style=\"WIDTH: 300px\">"
			+"<TR><TD Align=Center>To</TD>"
			+"<TD Align=Center><input type = text name=To></TD></TR>"
			+"<TR><TD Align=Center>CC</TD>"
			+"<TD Align=Center><input type=text name =CC></TD></TR>"
			+"<TR><TD Align=Center>From</TD>"
			+"<TD Align=Center><input type=text name =From></TD></TR>"
			+"<TR><TD Align=Center>Subject</TD>"
			+"<TD Align=Center><input type=text name =subject></TD></TR>"
			+"<TR><TD Align=Center>SMTP Host</TD>"
			+"<TD Align=Center><input type=text name=smtphost></TD></TR>"
			+"<TR><TD Align=Center>Text</TD>"
			+"<TD Align=Center><textarea name =textbody ROWS=10 COLS=60>"
			+"</textarea></TD></TR>"
			+"<TR><TD Align=Center>Content Type</TD>"
			+"<TD Align=Center><Select name=contenttype>"
			+"<Option selected value=\"text/plain\">Text/Plain"
			+"<Option value=\"text/html\">Text/HTML"
			+"</SELECT></TD></TR>"
			+"<TR><TD Align=Center><input type=submit value=\"Send Mail\"></TD></TR>"
			+"</TABLE></form></P>"
			+"<P><A HREF=/convention/AddMessage.html>Add new Message</A>"
			+"</body></html>");*/
		out.println(strBuf+"</body></html>");
		con.close();
    }catch(Exception e) 
	{
          e.printStackTrace();
	}
    out.close();
    }
    else response.sendRedirect("/convention/intro.html");

   }//end doget
   public void doPost(HttpServletRequest request,
                     HttpServletResponse response)
       throws IOException, ServletException
   {
       doGet(request, response);
   }
}//end class articles


