import java.io.*; 

import javax.servlet.*; 
import javax.servlet.http.*;

public class HelloWorld extends HttpServlet {

public void doGet(HttpServletRequest req, HttpServletResponse resp) 
  throws IOException, ServletException {
  resp.setContentType("text/html");
  PrintWriter out = resp.getWriter();
  out.println("<html><head><title>Hello</title></head><body>");
  out.println("Hello World");
  out.println("</body></html>");
} 
}

