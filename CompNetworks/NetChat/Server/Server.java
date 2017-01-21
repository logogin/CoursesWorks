/*
 * @(#)Server.java 1.0 03/11/09
 *
 * You can modify the template of this file in the
 * directory ..\JCreator\Templates\Template_2\Project_Name.java
 *
 * You can also create your own project template by making a new
 * folder in the directory ..\JCreator\Template\. Use the other
 * templates as examples.
 *
 */

import java.awt.*;
import java.awt.event.*;
import java.applet.*;
import javax.swing.*;
import java.util.*;
import java.io.*;
import java.net.*;
import javax.swing.event.*;

public class Server extends Applet
{
	protected ServerGUI gui=new ServerGUI();
	
	protected Vector vectorRooms;
	protected Vector vectorUsers;
	protected Hashtable hashRooms;
	protected Hashtable hashUsers;
	protected int port;
	
	boolean bAllRooms=false;
	
	protected ServerThread serverThread;
	
	public void init() 
	{
		port=Integer.parseInt(getParameter("port"));
		gui.buttonStop.setEnabled(false);
		//gui.listRooms.setEnabled(false);
		//gui.listUsers.setEnabled(false);
		setSize(521,377);
		add(gui);
		setListeners();
	}
	
	public void setListeners()
	{
		gui.buttonStart.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent event)
			{
				vectorRooms=new Vector();
				vectorRooms.add("All Rooms");
				vectorRooms.add("Main Room");
				vectorRooms.add("Room 1");
				vectorRooms.add("Room 2");
				vectorRooms.add("Room 3");
				vectorUsers=new Vector();
				hashRooms=new Hashtable();
				hashUsers=new Hashtable();
				
				gui.buttonStart.setEnabled(false);
				serverThread=getServerThread();
				serverThread.startServer(8000);
			}
		});
		
		
		gui.buttonStop.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent event)
			{
				gui.buttonStop.setEnabled(false);
				serverThread.stopServer();
				resetAll();
			}
		});
		
		gui.listRooms.addListSelectionListener(new ListSelectionListener()
		{
			public void valueChanged(ListSelectionEvent event)
			{
				//System.out.println("here");
				//System.out.println(vectorRooms);
				//System.out.println(gui.listRooms);
				//System.out.println(gui.listRooms.getSelectedIndex());
				if (!gui.listRooms.isSelectionEmpty())
					if (((String)gui.listRooms.getSelectedValue()).equals("All Rooms"))
					{
						bAllRooms=true;
						gui.listUsers.setListData(vectorUsers);
						gui.labelRoom.setText((String)gui.listRooms.getSelectedValue());
						gui.updateUI();
					}
					else
					{
						bAllRooms=false;
						gui.listUsers.setListData((Vector)hashRooms.get(
							(String)gui.listRooms.getSelectedValue()));
						gui.labelRoom.setText((String)gui.listRooms.getSelectedValue());
						gui.updateUI();
					}
			}
		});
	}
	
	public ServerThread getServerThread()
	{
		return new ServerThread(this);
	}
	
	public synchronized boolean isUser(String user)
	{
		return vectorUsers.contains(user);
	}
	
	public synchronized boolean isRoom(String room)
	{
		return vectorRooms.contains(room);	
	}
	
	public synchronized String getUserRoom(String user)
	{
		return ((User)hashUsers.get(user)).getRoom();
	}
	
	public synchronized void addUser(String name,String room,Socket socket,
		ObjectInputStream input,ObjectOutputStream output)
	{
		vectorUsers.add(name);
		User user=new User(name,room);
		user.setSocket(socket);
		user.setStreams(input,output);
		hashUsers.put(name,user);
		Vector vector=((Vector)hashRooms.get(room));
		vector.add(name);
		hashRooms.put(room,vector);
	}
	
	public synchronized void addRoom(String room)
	{
		vectorRooms.add(room);
		hashRooms.put(room,new Vector());
		gui.listRooms.setListData(vectorRooms);
		gui.updateUI();
	}
	
	public synchronized void removeRoom(String room)
	{
		vectorRooms.remove(room);
		hashRooms.remove(room);
	}
	
	public synchronized boolean isEmpty(String room)
	{
		return ((Vector)hashRooms.get(room)).isEmpty();
	}
	
	public synchronized void moveUser(String user,String room)
	{
		String oldRoom=((User)hashUsers.get(user)).getRoom();
		Vector vector=(Vector)hashRooms.get(oldRoom);
		vector.remove(user);
		hashRooms.put(oldRoom,vector);
		vector=(Vector)hashRooms.get(room);
		vector.add(user);
		hashRooms.put(room,vector);
		User userObject=(User)hashUsers.get(user);
		userObject.setRoom(room);
		hashUsers.put(user,userObject);
	}
	
	public synchronized Hashtable getHashRooms()
	{
		return hashRooms;
	}
	
	public synchronized Vector getVectorRooms()
	{
		return vectorRooms;	
	}
	
	public synchronized void sendToAll(Message message) throws IOException
	{
		for (int i=0; i<vectorUsers.size(); i++)
			((User)hashUsers.get(
				(String)vectorUsers.elementAt(i))).getOutput().writeObject(message);
	}
	
	public synchronized void sendToAll(String room,Message message) throws IOException
	{
		Vector vector=(Vector)hashRooms.get(room);
		for (int i=0; i<vector.size(); i++)
			((User)hashUsers.get(vector.elementAt(i))).getOutput().writeObject(message);
	}
	
	public synchronized void sendToUser(String user,Message message) throws IOException
	{
		((User)hashUsers.get(user)).getOutput().writeObject(message);
	}
	
	public synchronized void removeUser(String userName)
	{
		Vector vector;
		Vector vectorTo=(Vector)hashRooms.get("Main Room");
		User user=(User)hashUsers.get(userName);
		if (!(vector=user.getCreated()).isEmpty())
		{
			for (int i=0; i<vector.size(); i++)
			{
				Vector vectorFrom=(Vector)hashRooms.get((String)vector.elementAt(i));
				for (int j=0; j<vectorFrom.size(); i++)
				{
					String name=(String)vectorFrom.elementAt(j);
					vectorTo.add(name);
					User nextUser=(User)hashUsers.get(name);
					nextUser.setRoom("Main Room");
					hashUsers.put(name,nextUser);
				}
			}
			hashRooms.put("Main Room",vectorTo);
		}
		user=(User)hashUsers.get(userName);
		vectorUsers.remove(userName);
		vector=(Vector)hashRooms.get(user.getRoom());
		vector.remove(userName);
		hashRooms.put(user.getRoom(),vector);
		hashUsers.remove(userName);
		Message message=new Message(Message.codeSendUpdateTables);
		message.setVector(vectorRooms);
		message.setHashList(hashRooms);
		try
		{
			sendToAll(message);
		}
		catch (IOException ioException)
		{
			ioException.printStackTrace();		
		}
	}
	
	protected void resetAll()
	{
		for (int i=0; i<vectorUsers.size(); i++)	
		{
			User user=(User)hashUsers.get((String)vectorUsers.elementAt(i));
			try
			{
				user.getSocket().close();
			}
			catch (IOException ioException)
			{
				ioException.printStackTrace();
			}
		}
//		vectorUsers.removeAllElements();
//		vectorRooms.removeAllElements();
//		hashUsers.clear();
//		hashRooms.clear();
//		gui.listRooms.setEnabled(false);
//		gui.listUsers.setEnabled(false);
		gui.updateUI();
	}
	
	protected void closeAllConnections() throws IOException
	{
		for (int i=0; i<vectorUsers.size(); i++)
		{
			((User)vectorUsers.elementAt(i)).getSocket().close();
		}
	}
	
	protected void removeConnection( Socket s ) 
	{
		hashUsers.remove( s );
		try 
		{
        	s.close();
      	}
		catch( IOException ie ) 
		{
			ie.printStackTrace();
		}
	}
}
