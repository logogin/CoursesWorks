
import java.io.*;                                 
import javax.servlet.*; 
import javax.servlet.http.*;
import java.util.*;


public class CookieServlet extends HttpServlet {

public void doGet(HttpServletRequest req, HttpServletResponse resp) 
  throws IOException, ServletException {


  // html - content initiation
  resp.setContentType("text/html");
  PrintWriter out = resp.getWriter();
  out.println("<html><head><title></title></head><body>");
  out.println("<center>" +"<h3>" + "Simple Cookie demonstration" + "</h3>" + "</center>");
  out.println("<center>" + "click Refresh for servlet restarting" + "</center>" + "<br>");
  
     
  // Current  time  and  date
  Date dt = new Date();
  String todayString = dt.toString();
  
  
  //Create a new Cookie object.
  Cookie lastVisitTime = new Cookie("lastVisitTime", todayString);
  
  
  // Setting  the  cookie  life - time .
  // the  -1   value  is  default and  sets the cookie's life time DURING THIS SESSION ONLY
  // generally , the argument is defined in seconds and the cookie is stored  on the
  // client's  computer  when brouser is offline . 
  lastVisitTime.setMaxAge(-1);
  
  
  //Send the cookie back to the browser by associating the cookie 
  //object with the servlet response object:
  resp.addCookie(lastVisitTime);
  
 
  
  //Accessing ALL  the cookies  associated with  this  servlet as  the array of cookies 
  Cookie[] myCookies = req.getCookies();
  
  
  
  //Use the Cookie object's getName and getValue methods to access cookies and their values.
  //This example displays cookie names and their associated values:
  if  (myCookies != null) 
  out.println("Cookie Name   ...........  "      + "Cookie  Value" + "<hr>"); 
  {
  for(int i=0; i<myCookies.length; i++) {
    out.println(myCookies[i].getName()+ "   ...........  " + myCookies[i].getValue() + "<br>");
   } 
  } 
 

   // End of  html- content
   out.println("</body></html>"); 
   
} 
}



















