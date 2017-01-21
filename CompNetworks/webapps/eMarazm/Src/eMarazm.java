import java.io.*;
import java.util.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class eMarazm extends HttpServlet
{
	static String DATABASE_URL="jdbc:mysql://localhost:3306/eMarazm";
	final static String BADLOGIN_PAGE="/eMarazm/badlogin.html";
	final static String ERROR_PAGE="/eMarazm/error.html";
	final static String NOACCESS_PAGE="/eMarazm/noaccess.html";
	final static String UPDATED_PAGE="/eMarazm/updated.html";
	final static String EXIST_PAGE="/eMarazm/exist.html";
	final static String SENT_PAGE="/eMarazm/sent.html";
	final static String INDEX_PAGE="/eMarazm/leave.html";
	
	final static int SINGLE_CHOICE=0;
	final static int MULTI_CHOICE=1;
	final static int MAX_MESSAGES=50;
	
	final static int GROUPS_NUMBER=3;
	final static int ADMIN_GROUP=0;
	final static int LECTOR_GROUP=1;
	final static int STUDENT_GROUP=2;
	final static String groups[]={"admin","lector","student"};
	final static String groupString[]={"Administrators","Lectors","Students"};
	
	HttpServletRequest request;
	HttpServletResponse response;
	ServletContext context;
	HttpSession session;
	PrintWriter out;
	Connection connection;
	Statement statement;
	StringBuffer buffer;
	
	
	public void getHttpContext(HttpServletRequest request,HttpServletResponse response)
	{
		this.request=request;
		this.response=response;	
	}
	
	public HttpSession getSession(boolean create)
	{
		this.session=request.getSession(create);
		return this.session;
	}
	
	public ServletContext getContext()
	{
		this.context=getServletContext();
		return this.context;
	}
	
	public void setContentType(String type)
	{
		response.setContentType(type);
	}
	
	public PrintWriter getWriter() throws IOException
	{
		this.out=response.getWriter();	
		return this.out;
	}
	
	public StringBuffer readFile(String file) throws IOException
	{
		BufferedReader in=null;
        this.buffer=new StringBuffer();
        String line;
        try
        {
        	in=new BufferedReader(new FileReader(
        		getServletContext().getRealPath(file)));
        	while((line=in.readLine())!=null)
        			buffer.append(line+"\n");
        }
        
        finally
        {
        	if (in != null)
        		in.close();  	
        }
        
        return this.buffer;
	}
	
	public void sendRedirect(String address) throws IOException
	{
		response.sendRedirect(address);
	}
	
	Connection connectDataBase() throws IOException
	{
		connection=null;
		try
		{
			Class.forName("com.mysql.jdbc.Driver").newInstance();
			connection = DriverManager.getConnection(DATABASE_URL,"root","");
		}
		
		catch (Exception exception)
		{
			exception.printStackTrace();
			response.sendRedirect(ERROR_PAGE);
			return connection;	
		}
		return connection;
	}
	
	public Statement newStatement() throws SQLException
	{
		return connection.createStatement();
	}
	
	public ResultSet executeQuery(String query) throws SQLException
	{
		return newStatement().executeQuery(query);
	}
	
	public void executeUpdate(String update) throws SQLException
	{
		newStatement().executeUpdate(update);
	}
	
	public int insertToken(StringBuffer buffer,int curPos,String token,
		String string)
	{
		int result=buffer.indexOf(token,curPos)+token.length();
		buffer.insert(result,string);
		return result;
	}
	
	public boolean isGroup(String group,int test_group)
	{
		return groups[test_group].equals(group);
	}
	
	public String getGroupString(String group)
	{
		for (int i=0; i<GROUPS_NUMBER; i++)
			if (isGroup(group,i))
				return groupString[i];
		return new String("N/A");
	}
	public String getCurrentTime()
	{
		Calendar currentDate=Calendar.getInstance();
		String stringDate=currentDate.get(Calendar.YEAR)+"-"
			+currentDate.get(Calendar.MONTH)+"-"
			+currentDate.get(Calendar.DAY_OF_MONTH)+" "
			+currentDate.get(Calendar.HOUR_OF_DAY)+":"
			+currentDate.get(Calendar.MINUTE)+":"
			+currentDate.get(Calendar.SECOND);
		return stringDate;
	}
	
	public boolean addLogEntry(String entry)
	{
		try
		{
			executeUpdate("insert into logs (entryDate,message) values ('"
				+getCurrentTime()+"','"+formatString(entry)+"')");
		}
		catch (SQLException sqlException)
		{
			sqlException.printStackTrace();
			return false;				
		}
		return true;
	}
	
	public String formatString(String string)
	{
		if (string==null)
			return string;
		String result="";
		for (int i=0; i<string.length(); i++)
			if (string.charAt(i)!='\'')
				result+=string.charAt(i);
			else
				result+="\\'";
		return result;
	}
}