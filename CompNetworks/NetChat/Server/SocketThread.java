
import java.io.*;
import java.net.*;
import java.util.*;

import java.util.*;

public class SocketThread extends Thread
{
	protected Server server; 
	protected Socket socketUser;
	
	protected ObjectInputStream input;
	protected ObjectOutputStream output; 
	
	protected String userName;
	boolean bGotUser=false;

	public SocketThread(Server server,Socket socket)
	{
		this.server=server;
		socketUser=socket;
		try
		{
			output=new ObjectOutputStream(socketUser.getOutputStream());
			output.flush();
			input=new ObjectInputStream(socketUser.getInputStream());
		}
		
		catch (IOException ioException)
		{
			ioException.printStackTrace();
			//server.removeUser(socketUser);
		}
		start();
	}
	
	public void run()
	{
		//System.out.println("Here");
		try
		{
			do
			{
				ProcessMessage(ReadMessage());
			}
			while (true);
		}
	
		catch (NullPointerException nullPointerException)
		{
			nullPointerException.printStackTrace();
		}
			
		catch (EOFException eofException)
		{
			eofException.printStackTrace();
			server.gui.areaSystem.append("Connection to host "+
				socketUser.getInetAddress().getHostAddress()+":"+socketUser.getPort()+" lost\n");
			server.removeConnection(socketUser);
			if (bGotUser)
				server.removeUser(userName);
			try
			{	
				socketUser.close();
			}
			catch (IOException ioException)
			{
				ioException.printStackTrace();
			}
		}
		
		catch (IOException ioException)
		{
			server.gui.areaSystem.append("Connection to host "+
				socketUser.getInetAddress().getHostAddress()+":"+socketUser.getPort()+" lost\n");
			server.removeConnection(socketUser);
			ioException.printStackTrace();
			if (bGotUser)
				server.removeUser(userName);
			try
			{	
				socketUser.close();
			}
			catch (IOException ioException1)
			{
				ioException1.printStackTrace();
			}
		}
			
		catch (ClassNotFoundException classNotFound)
		{
			classNotFound.printStackTrace();
			if (bGotUser)
				server.removeUser(userName);	
			try
			{	
				socketUser.close();
			}
			catch (IOException ioException)
			{
				ioException.printStackTrace();
			}
		}
		
		finally
		{
			server.gui.areaSystem.append("Removing connection to: "+
				socketUser.getInetAddress().getHostAddress()+":"+socketUser.getPort()+"\n");
			server.removeConnection(socketUser);
		}
	}
	
	protected Message ReadMessage() throws ClassNotFoundException,IOException
	{
		return (Message)input.readObject();
	}
	
	protected void ProcessMessage(Message message) throws IOException,NullPointerException
	{
		String room;
		String textSend;
		
		/*if((String)message.getString()=="Left the chat")
			server.removeConnection(socketUser);*/
		switch (message.getCode())
		{
			case Message.codeSendUserName:
				userName=message.getString();
				//System.out.println(userName);
				if (server.isUser(userName))
				{
					message=new Message(Message.codeSendUserNameResponse);
					message.setFailure(true);
					output.writeObject(message);
				}
				else
				{
					
					message=new Message(Message.codeSendUserNameResponse);
					message.setFailure(false);
					message.setHashList(server.getHashRooms());
					message.setVector(server.getVectorRooms());
					output.writeObject(message);
					
					server.addUser(userName,"Main Room",socketUser,input,output);
					bGotUser=true;
					server.gui.areaSystem.append("New user \""+userName+"\" accepted\n");
					
					message=new Message(Message.codeSendAddNewUser);
					message.setString(userName);
					server.sendToAll(message);
				}
			break;
			
			case Message.codeSendMoveToRoom:
				room=message.getString();
				System.out.println(room);
				if (server.isRoom(room))
				{
					server.moveUser(userName,room);
					server.gui.areaSystem.append("User \""+userName+"\" entered room \""
							+room+"\"\n");
					message=new Message(Message.codeSendMoveToRoomResponse);
					message.setFailure(false);
					message.setString(userName);
					Vector vector=new Vector();
					vector.add(room);
					message.setVector(vector);
					server.sendToAll(message);
				}
				else
				{
					message=new Message(Message.codeSendMoveToRoomResponse);
					message.setFailure(true);
					output.writeObject(message);
				}
				//System.out.println()
			break;
			
			case Message.codeSendCreateRoom:
				System.out.println("here");
				room=message.getString();
				//System.out.println("1 "+room);
				if (server.isRoom(room))
				{
					//System.out.println("here 1");
					message=new Message(Message.codeSendCreateRoomResponse);
					message.setFailure(true);
					output.writeObject(message);
				}
				else
				{
					//System.out.println("here 2");
					server.addRoom(room);
					server.gui.areaSystem.append("User \""+userName+"\" created room \""
						+room+"\"\n");
					message=new Message(Message.codeSendCreateRoomResponse);
					message.setFailure(false);
					Vector vector=new Vector();
					message.setString(userName);
					vector.add(room);
					message.setVector(vector);
					server.sendToAll(message);					
				}
			break;
			
			case Message.codeSendRemoveRoom:
				room=message.getString();
				if (server.isEmpty(room))
				{
					server.removeRoom(room);
					server.gui.areaSystem.append("User \""+userName+"\" removed room \""
						+room+"\"\n");
					message=new Message(Message.codeSendRemoveRoomResponse);
					message.setFailure(false);
					message.setString(userName);
					Vector vector=new Vector();
					vector.add(room);
					message.setVector(vector);
					server.sendToAll(message);
				}
				else
				{
					message=new Message(Message.codeSendRemoveRoomResponse);
					message.setFailure(true);
					output.writeObject(message);
				}
			break;
			
			case Message.codeSendMessage:
				room=server.getUserRoom(userName);
				textSend="["+userName+"] "+message.getString()+"\n";
				
				message.setString(textSend);
				server.sendToAll(room,message);
				if (server.bAllRooms)
				{
					textSend="["+room+"]"+textSend;
					server.gui.areaChat.append(textSend);
				}
				if (((String)server.gui.listRooms.getSelectedValue()).equals(room))
					server.gui.areaChat.append(textSend);
			break;
			
			case Message.codeSendPrivate:
				room=server.getUserRoom(userName);
				String user=(String)message.getVector().elementAt(0);
				textSend="Private>"+"["+userName+"] to ["+
					user+"] "+message.getString()+"\n";
				
				message.setString(textSend);
				Vector vector=new Vector();
				vector.add(userName);
				message.setVector(vector);
				server.sendToUser(user,message);
				server.sendToUser(userName,message);
				if (server.bAllRooms)
				{
					textSend="["+room+"]"+textSend;
					server.gui.areaChat.append(textSend);
				}
				if (((String)server.gui.listRooms.getSelectedValue()).equals(room))
					server.gui.areaChat.append(textSend);
			break;
			
			case Message.codeRemoveUser:
				//server.removeConnection(socketUser);
				if((String)message.getString()=="Left the chat")
			server.removeConnection(socketUser);
				server.hashUsers.remove(socketUser);
			break;
		}
	}
}
