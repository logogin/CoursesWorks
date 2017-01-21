import java.io.*; 
import javax.servlet.*; 
import javax.servlet.http.*;

public class HandleForm extends HttpServlet {

public void doGet(HttpServletRequest req, HttpServletResponse resp) 
  throws IOException, ServletException {
  
  resp.setContentType("text/html");
  PrintWriter out = resp.getWriter();
  
    // getting  parameters  from the form
  String  ItemNumber = req.getParameter("itemNum");
  String  Quantity   = req.getParameter("quantity");
  String  Price      = req.getParameter("price");
  String  FirstName  = req.getParameter("firstName");
  String  LastName   = req.getParameter("lastName");
  String  Initial    = req.getParameter("initial");
  String  Address    = req.getParameter("address");
  String  CardType   = req.getParameter("cardType");
  String  CardNum    = req.getParameter("cardNum");
  String  Notes      = req.getParameter("notes");
  
  
    // printing  the  parameters
  out.println("<html><head><title>HandleForm</title></head><body>");
  //
  out.println("Item  Number  :"      +   ItemNumber + "<br>");
  out.println("Quantity      :"      +   Quantity   + "<br>");
  out.println("Price         :"      +   Price      + "<br>");
  out.println("First Name    :"      +   FirstName  + "<br>");
  out.println("Last  Name    :"      +   LastName   + "<br>");
  out.println("Middle Initial:"      +   Initial    + "<br>");
  out.println("Address       :"      +   Address    + "<br>");
  out.println("Card  Type    :"      +   CardType   + "<br>");
  out.println("Card  Number  :"      +   CardNum    + "<br>");
  out.println("Your special notes:"  +   Notes      + "<br>");
  //
  out.println("</body></html>");
}  //end  doGet




public void doPost(HttpServletRequest req, HttpServletResponse resp) 
  throws IOException, ServletException {
  doGet(req,resp);
  } //end doPost

 
}// end  class

