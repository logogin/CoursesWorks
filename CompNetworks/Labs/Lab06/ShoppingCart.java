import   javax.servlet.*;
import   javax.servlet.http.*;
import   java.io.*;
import   java.util.*;


public  class  ShoppingCart  extends  HttpServlet 
{


   public  void  doGet(HttpServletRequest  request , HttpServletResponse response)
      throws  ServletException , IOException 
      {
	       
		    // head of the  html - content
	    response.setContentType("text/html");
		PrintWriter  out = response.getWriter();
		out.println("<html>");
		out.println("<head><title> Shopping cart </title> </head> <body>");
		   
		   
		
		 // opening or accessing the  session  object
		HttpSession   session = request.getSession(true);
		
		
		
		 // printing  the  session  information    
		out.println("<center><h3>Current session information : </h3></center>");
		out.println("Session ID       :   " + session.getId() +  "<br>");
		out.println("New session ?    :   " + session.isNew() +  "<br>");
		out.println("Creation Time    :   " + new Date(session.getCreationTime()) +  "<br>");
		out.println("Last Access Time :   " + new Date(session.getLastAccessedTime()) +  "<br>");
		out.println("<hr> <br>");
		
		
		  // getting the movie ordered by customer
		String  OrderedMovie = request.getParameter("MovieToOrder");

	
		
		 // updating  shopping  cart
		Vector  Cart; 
		synchronized(session) 
		{
		      Cart = (Vector)session.getValue("ShoppingCart");
			  if (Cart == null) 
			     {
				   Cart = new Vector();
			     }
			  Cart.add(OrderedMovie);
			  session.putValue("ShoppingCart",Cart);
		}
		
	  
	    
		 //  printing  the  shopping cart
		out.println("<center><h3>Your shopping card includes : </h3></center>"); 		
		for(int x=0; x < Cart.size(); x++ ) 
		{
		  out.println(Cart.get(x) + "<br>");
		}
	 
	 
	     // end  of  html - content
		out.println("</body> </html>");
	  
      }

      
} 



  