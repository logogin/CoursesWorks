import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class viewchatlog extends HttpServlet {
    public void doGet(HttpServletRequest request,
                        HttpServletResponse response)
                        throws ServletException, IOException
   {
   
   	   response.setContentType("text/html");
       PrintWriter out = response.getWriter();
       out.println("<html><head><title>chat log</title></head><body>");
       out.println("<body bgcolor=lightskyblue>");
       out.println("<h1>chat log</h1>");
   try{
		//Code to read from file
           String inputFileName =
              System.getProperty("user.home",
              File.separatorChar + "home" +
              File.separatorChar + "zelda") +
              File.separatorChar + "chat_log.txt";
           File fin = new File(inputFileName);
           RandomAccessFile rin = new RandomAccessFile(fin, "r");
           StringBuffer strBuf = new StringBuffer();
           strBuf.append("<hr><br>");
		   
		   while (rin.getFilePointer()!=rin.length()) 	           
		   		strBuf.append("<br>"+rin.readLine());
           out.println(strBuf);
		   rin.close();
   } catch( IOException ie ) 
    		{ System.out.println( ie ); }
   }
   public void doPost(HttpServletRequest request,
                     HttpServletResponse response)
       throws IOException, ServletException
   {
       doGet(request, response);
   }
}//end class 


