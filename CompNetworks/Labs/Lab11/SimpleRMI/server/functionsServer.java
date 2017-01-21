import java.net.*;
import java.rmi.*;

public class functionsServer
{
	public static void main(String[] args)
	{
	try
	{
	FunctionsImpl f = new FunctionsImpl();
		Naming.rebind("mosh",f);
			System.out.println("functions Server ready");
		}
		catch (RemoteException re)
		{
			System.out.println(re);
		}
			catch (MalformedURLException e)
		{
			System.out.println( e);
		}
	}
}	