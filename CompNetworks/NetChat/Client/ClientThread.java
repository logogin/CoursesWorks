
import java.io.*;
import java.net.*;
import java.util.*;
import javax.swing.*;

public class ClientThread extends Thread
{
	protected Client client;
	protected Socket socketClient;
	
	protected String host;
	protected int port;
	protected String userName;
	protected String room;
	
	protected ObjectInputStream input;
	protected ObjectOutputStream output;
	
	
	public ClientThread(Client client)
	{
		this.client=client;
	}
	
	public void Connect(String host,int port)
	{
		this.host=host;
		this.port=port;
		start();
	}
	
	public void Disconnect()
	{
		try
		{
			Message message=new Message(Message.codeSendMessage);
			message.setString("Left the chat");
			output.writeObject(message);
			socketClient.close();
			client.resetAll();
		}
		
		catch (IOException ioException)
		{
			ioException.printStackTrace();
			try
			{
				socketClient.close();
			}
			catch (IOException ioExcept)
			{
				ioExcept.printStackTrace();
			}
			client.resetAll();	
			return;
		}
		
	}
    
	public void run()
	{
		try
		{
			socketClient=new Socket(host,port);
		
			output=new ObjectOutputStream(socketClient.getOutputStream());
			output.flush();
			input=new ObjectInputStream(socketClient.getInputStream());
			
			client.gui.buttonDisconnect.setEnabled(true);
			client.gui.labelStatus.setText("Client connected ...");
			SendUserName();
			do
			{
				ProcessMessage(ReadMessage());
			}
			while(true);
		}
		
		catch (ConnectException socketException)
		{
			//socketException.printStackTrace();
			JOptionPane.showMessageDialog(null,"Unable to connect to server\nServer is unreachable","Warning",
				JOptionPane.ERROR_MESSAGE);
			client.resetAll();
			return;
		}
		
		catch (EOFException eofException)
		{
			eofException.printStackTrace();
			JOptionPane.showMessageDialog(null,"Connection to server lost...","Warning",
				JOptionPane.WARNING_MESSAGE);
			client.resetAll();
			return;
		}
		
		catch (IOException ioException)
		{
			ioException.printStackTrace();	
			client.resetAll();	
			return;
		}
		
		catch (ClassNotFoundException classNotFound)
		{
			classNotFound.printStackTrace();
			client.resetAll();	
			return;
		}
	}
	
	protected void SendUserName() throws IOException
	{
		Message message;
		try
		{
			do
			{
				userName=JOptionPane.showInputDialog("Enter your name: ");
				if (userName.equals(""))
					JOptionPane.showMessageDialog(null,"Invalid name","Error",
						JOptionPane.ERROR_MESSAGE);
			}
			while(userName.equals("")&&userName!=null);
		}
		
		catch (NullPointerException nullPointer)
		{
			socketClient.close();
			client.gui.buttonConnect.setEnabled(true);
			client.gui.buttonDisconnect.setEnabled(false);
			client.resetAll();
			stop();
			return;
		}
		
		message=new Message(Message.codeSendUserName);
		message.setString(userName);
		//System.out.println(userName);
		output.writeObject(message);
	}
	
	protected Message ReadMessage() throws IOException,ClassNotFoundException, EOFException
	{
		return (Message)input.readObject();
	}
	
	public void sendMessage(Message message)
	{
		try
		{
			output.writeObject(message);
		}
		
		catch (EOFException eofException) {}
		
		catch (IOException ioException)
		{
			JOptionPane.showMessageDialog(null,"Error sending message...","Error",
				JOptionPane.ERROR_MESSAGE);
			ioException.printStackTrace();
			client.resetAll();
			return;
		}
	}
	
	protected void ProcessMessage(Message message) throws IOException
	{
		switch (message.getCode())
		{
			case Message.codeSendUserNameResponse:
				if (message.isFailure())
				{
					JOptionPane.showMessageDialog(null,"User already exists","Error",
						JOptionPane.ERROR_MESSAGE);	
					SendUserName();
				}
				else
				{
					client.user=new User(userName,"Main Room");
					client.gui.labelRoom.setText("Main Room");
					client.gui.labelUser.setText(userName);
					client.gui.updateUI();
					client.setDefaults(true);
					client.setHashRooms(message.getHashList());
					client.setVectorRooms(message.getVector());
					
					message=new Message(Message.codeSendMessage);
					message.setString("Hello, everyone!!!");
					output.writeObject(message);
				}
			break;
			
			case Message.codeSendAddNewUser:
				client.addNewUser(message.getString());
			break;
			
			case Message.codeSendMoveToRoomResponse:
				if (!message.isFailure())
				{
					room=(String)message.getVector().elementAt(0);
					System.out.println(room);
					client.moveUser(message.getString(),room);
					if (message.getString().equals(userName))
					{
						client.user.setRoom(room);
						client.gui.labelRoom.setText(room);
						client.gui.buttonGoto.setEnabled(true);
						message=new Message(Message.codeSendMessage);
						message.setString("Hello, everyone!!!");
						output.writeObject(message);
					}	
				}
				else
				{
					JOptionPane.showMessageDialog(null,"Room not exists","Error",
							JOptionPane.ERROR_MESSAGE);
					client.gui.buttonGoto.setEnabled(true);
				}
			break;
			
			case Message.codeSendCreateRoomResponse:
			//	System.out.println("Here");
				if (!message.isFailure())
				{
					room=(String)message.getVector().elementAt(0);
					System.out.println(room);
					client.addRoom(room);
					if (message.getString().equals(userName))
					{
						client.user.addRoom(room);
						client.gui.buttonCreate.setEnabled(true);
					}
				}
				else
				{
					JOptionPane.showMessageDialog(null,"Room already exists","Error",
						JOptionPane.ERROR_MESSAGE);
					client.gui.buttonCreate.setEnabled(true);
				}
			break;
			
			case Message.codeSendRemoveRoomResponse:
				if (!message.isFailure())
				{
					room=(String)message.getVector().elementAt(0);
					client.removeRoom(room);
					if (message.getString().equals(userName))
					{
						client.user.removeRoom(room);
						//client.gui.buttonRemove.setEnabled(true);
					}
				}
				else
				{
					JOptionPane.showMessageDialog(null,"Room is not empty","Error",
						JOptionPane.ERROR_MESSAGE);
					client.gui.buttonRemove.setEnabled(true);
				}
			break;
			
			case Message.codeSendPrivate:
			case Message.codeSendMessage:
				client.gui.areaChat.append(message.getString());
			break;
			
			case Message.codeSendUpdateTables:
				boolean flag=false;
				client.setVectorRooms(message.getVector());
				client.setHashRooms(message.getHashList());
				for (int i=0; i<client.vectorRooms.size()&&!flag; i++)
				{
					if (((Vector)client.hashRooms.get(
						(String)client.vectorRooms.elementAt(i))).contains(
							client.user.getName())&&!client.user.getRoom().equals(
								(String)client.vectorRooms.elementAt(i)))
					{
						flag=true;
						message=new Message(Message.codeSendMessage);
						message.setString("Hello, everyone!!!");
						output.writeObject(message);
					}
				}
			break;
		}
	}
}
