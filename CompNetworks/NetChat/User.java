
import java.io.*;
import java.net.*;
import java.util.*;

public class User 
{
	final static int maxRooms=3;
	
	protected String userName;
	protected Socket userSocket;
	protected ObjectInputStream userInput;
	protected ObjectOutputStream userOutput;
	protected String userRoom;
	protected Vector vectorCreated=new Vector();
	protected int userCreated=0;

	public User(String name,String room)
	{
		setName(name);
		setRoom(room);
	}
	
	public void setName(String name)
	{
		userName=name;
	}
	
	public String getName()
	{
		return userName;	
	}
	
	public void setSocket(Socket socket)
	{
		userSocket=socket;
	}
	
	public Socket getSocket()
	{
		return userSocket;
	}
	
	public void setStreams(ObjectInputStream input, ObjectOutputStream output)
	{
		userInput=input;
		userOutput=output;	
	}
	
	public ObjectInputStream getInput()
	{
		return userInput;
	}
	
	public ObjectOutputStream getOutput()
	{
		return userOutput;	
	}
	
	public void setRoom(String room)
	{
		userRoom=room;
	}
	
	public String getRoom()
	{
		return userRoom;
	}	
	
	public boolean canCreate()
	{
		if (userCreated<maxRooms)
			return true;
		else
			return false;
	}
	
	public boolean addRoom(String room)
	{
		if (!canCreate())
			return false;
		userCreated++;
		vectorCreated.add(room);
		return true;
	}
	
	public void removeRoom(String room)
	{
		if (vectorCreated.remove(room))
			userCreated--;	
	}
	
	public Vector getCreated()
	{
		return vectorCreated;
	}
}
