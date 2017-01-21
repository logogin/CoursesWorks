import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.util.*;
import java.sql.*;//for sql servers...

public class MessageBoard extends HttpServlet {
    public void doGet(HttpServletRequest request,
                        HttpServletResponse response)
                        throws ServletException, IOException
   {
        
HttpSession   session = request.getSession(true);
String str=(String)session.getValue("login");
if(str!=null && str.equals("true"))
{ 

   		Statement stmt,stmt_tmp;//used for database access
   		ResultSet resultSet,resultset_tmp;//used for database access
	
		response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        out.println("<html><head><title>MessageBoard</title></head><body>");
        out.println("<body bgcolor=lightskyblue>");
        out.println("<h1>Message Board</h1>");
    try{
    	//Register the JDBC driver
    	Class.forName("org.gjt.mm.mysql.Driver");  
    	//Construct URL for database on localhost
    	String url = "jdbc:mysql://localhost:3306/forum";
    	//Get a connection to the database:  port/name of db...
    	Connection con = DriverManager.getConnection(url,"",""); 
    	stmt = con.createStatement();
    	resultSet = stmt.executeQuery(
    	  "SELECT  count(*) FROM msgboard ");
    	resultSet.next();
    	Object obj1 = resultSet.getObject(1);
    	int num=Integer.parseInt(obj1.toString());
    	stmt = con.createStatement();
    	resultSet = stmt.executeQuery("SELECT * from msgboard");
    	//Get info about the ResultSet
        String []name=new String[num];
		String []email=new String[num];
		String []msg=new String[num];
		int i=0;
		while(resultSet.next()) {
			name[i] = (resultSet.getObject(1)).toString();
		   email[i] = (resultSet.getObject(2)).toString();
		     msg[i] = (resultSet.getObject(3)).toString();
			i++;
		}	
		StringBuffer strBuf = new StringBuffer();
		strBuf.append("<hr><br>");
		
		for(i=num-1;i>=0;i--)
		{
			strBuf.append("<hr><br>name:"+name[i]
			             +"<br>email:"+email[i]
						 +"<br>msg:"+msg[i]);
					
		} 
		out.println(strBuf);
		con.close();
    }catch(Exception e) {
               e.printStackTrace();
		}
       out.println("</body></html>");
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
}//end class showforum




/*Code to read from file
           String inputFileName =
              System.getProperty("user.home",
              File.separatorChar + "home" +
              File.separatorChar + "monicap") +
              File.separatorChar + "Messages.txt";
           File fin = new File(inputFileName);
           RandomAccessFile rin = new RandomAccessFile(fin, "r");
		   String strarr[]=new String[1000];
		   int i=0;
		   while (rin.getFilePointer()!=rin.length()) 	           
		   				strarr[i++]=rin.readLine();
		   for(int j=i-1;j>=0;--j)
		   {
		   	out.println("<p>"+strarr[j]);
		   }
           rin.close();*/
