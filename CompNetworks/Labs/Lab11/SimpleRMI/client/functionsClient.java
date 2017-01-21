import java.rmi.*;
import java.net.*;

public class functionsClient
{
	public static void main(String[] args)
	{
			try
		{
		SecurityManager s = System.getSecurityManager();
     if (s != null)
       s.checkConnect("localhost",1099);
			Object obj = Naming.lookup("rmi://localhost/mosh");
			functions remoteFunc =  (functions) obj;
			System.out.println(remoteFunc.addNumbers(2,3));
			System.out.println(remoteFunc.subNumbers(5,3));
		} //of try
catch (MalformedURLException e)
		{
			System.err.println("not a valid RMI URL");
		}
		catch (RemoteException e)
		{
			System.err.println("Remote object threw exception " + e);
		}
catch (NotBoundException e)
{
	System.err.println(
	"could not find requested remote object on the server");
}


	}

}