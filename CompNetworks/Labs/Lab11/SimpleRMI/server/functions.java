import java.rmi.*;

public interface functions extends Remote
{
	public int addNumbers(int a,int b) throws RemoteException;
	public int subNumbers(int a,int b) throws RemoteException;
}

