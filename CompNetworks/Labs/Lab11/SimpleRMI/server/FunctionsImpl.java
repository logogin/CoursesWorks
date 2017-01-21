import java.rmi.*;
import java.rmi.server.UnicastRemoteObject;

public class FunctionsImpl implements functions
{
public FunctionsImpl() throws RemoteException
	{
		UnicastRemoteObject.exportObject(this);
	}
public int addNumbers(int a,int b) throws RemoteException
{
	return a+b;
}
public int subNumbers(int a,int b) throws RemoteException
{
	return a-b;
}
}
