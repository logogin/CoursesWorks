import java.net.*;
import java.security.*;
import java.io.*;
import java.text.*;
import java.util.*;
import javax.servlet.*;
import javax.servlet.http.*;
import javax.crypto.*;

public class Encrypt extends HttpServlet {


    
    public void doGet(HttpServletRequest request,
                      HttpServletResponse response)
        throws IOException, ServletException
    {

        response.setContentType("text/html");

        PrintWriter out = response.getWriter();
        out.println("<html>");
        out.println("<body>");
        out.println("<head>");
        out.println("</head>");
        out.println("<body bgcolor=\"white\">");

 Enumeration paramNames=request.getParameterNames();
try
{

while (paramNames.hasMoreElements())
{
	String paramName=(String)paramNames.nextElement();
	String[] paramValue = request.getParameterValues(paramName);
	out.println("Value Before Encryption of "+paramName+" = "+paramValue[0]+"<BR>");
	KeyGenerator keyGen = KeyGenerator.getInstance("DES");
    keyGen.init(56);
    Key key = keyGen.generateKey();
	Cipher cipher = Cipher.getInstance("DES/ECB/PKCS5Padding");
 	cipher.init(Cipher.ENCRYPT_MODE, key);
	byte[] plaintext = paramValue[0].getBytes();
	byte[] cipherText  = cipher.doFinal(plaintext);
    out.println("Encrypted Value Of "+paramName+" = "+( new String(cipherText))+"<BR>");   
	Cipher cipher2 = Cipher.getInstance("DES/ECB/PKCS5Padding");
	cipher2.init(Cipher.DECRYPT_MODE, key);
    byte[] newPlainText = cipher2.doFinal(cipherText);
out.println("Decrypted Values of "+paramName+" = "+(new String(newPlainText))+"<BR>");
}
} //of try
catch(IllegalBlockSizeException e)
{
out.println(e);
}
catch(InvalidKeyException e)
{
	out.println(e);
}
catch(BadPaddingException e)
{
out.println(e);
}
catch(NoSuchAlgorithmException e)
{
	out.println(e);
}
catch(NoSuchPaddingException e)
{
out.println(e);
}
    }
	    public void doPost(HttpServletRequest request,
                      HttpServletResponse response)
        throws IOException, ServletException
    {
        doGet(request, response);
    }

}
