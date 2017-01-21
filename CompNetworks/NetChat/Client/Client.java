/*
 * @(#)Client.java 1.0 03/11/09
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
import javax.swing.event.*;

public class Client extends Applet 
{
	protected ClientGUI gui=new ClientGUI();
	protected ClientThread clientThread;

	protected Hashtable hashRooms;
	protected Vector vectorRooms;
	protected User user;
	protected String privateName;
	protected boolean sendPrivate=false;
	protected String host;
	protected int port;
	
	public void init() 
	{
		host=getParameter("host");
 		port=Integer.parseInt(getParameter("port"));

		setSize(736,390);
		add(gui);
		setDefaults(false);
		setListeners(this);
	}
	
	public void setDefaults(boolean flag)
	{
		//gui.buttonDisconnect.setEnabled(flag);
		gui.buttonSend.setEnabled(flag);
		gui.buttonClear.setEnabled(flag);
		gui.fieldMessage.setEnabled(flag);
		gui.buttonGoto.setEnabled(flag);
		gui.buttonRemove.setEnabled(flag);
		gui.buttonCreate.setEnabled(flag);
		gui.buttonPrivate.setEnabled(flag);
		gui.buttonUnprivate.setEnabled(flag);
	}
	
	public void setListeners(final Client clientInstance)
	{
		gui.buttonConnect.addActionListener(new ActionListener ()
		{
			public void actionPerformed(ActionEvent event)
			{
				vectorRooms=new Vector();
				hashRooms=new Hashtable();
				sendPrivate=false;
				gui.buttonConnect.setEnabled(false);				
				clientThread=new ClientThread(clientInstance);
				clientThread.Connect(host,port);
			}
		});
		
		gui.buttonDisconnect.addActionListener(new ActionListener ()
		{
			public void actionPerformed(ActionEvent event)	
			{
				gui.buttonDisconnect.setEnabled(false);
				Message message=new Message(Message.codeRemoveUser);
				clientThread.sendMessage(message);
				clientThread.Disconnect();
				clientThread.stop();
				gui.areaChat.setText("");
			}
		});
		
		gui.fieldMessage.addActionListener(new ActionListener ()
		{
			public void actionPerformed(ActionEvent event)
			{
				Message message;
				if (sendPrivate)
				{
					message=new Message(Message.codeSendPrivate);
					Vector vector=new Vector();
					vector.add(privateName);
					message.setVector(vector);
					
				}
				else
				{
					message=new Message(Message.codeSendMessage);
				}
				message.setString(gui.fieldMessage.getText());
				gui.fieldMessage.setText("");
				clientThread.sendMessage(message);
			}
		});

		gui.buttonGoto.addActionListener(new ActionListener ()
		{
			public void actionPerformed(ActionEvent event)
			{
				if (gui.listRooms.getSelectedIndex()!=-1)
				{
					gui.buttonGoto.setEnabled(false);
					Message message=new Message(Message.codeSendMoveToRoom);
					message.setString((String)gui.listRooms.getSelectedValue());
					clientThread.sendMessage(message);
					//System.out.println(message.getString());
				}
			}
		});
		
		gui.buttonCreate.addActionListener(new ActionListener ()
		{
			public void actionPerformed(ActionEvent event)
			{
				String room;
				if (!user.canCreate())
				{
					JOptionPane.showMessageDialog(null,"You cannot create more rooms",
					"Warning",JOptionPane.WARNING_MESSAGE);
					gui.buttonCreate.setEnabled(false);
					return;
				}
				
				gui.buttonCreate.setEnabled(false);
				
				try
				{
					do
					{
						room=JOptionPane.showInputDialog("Enter room name:");
						if (room.equals(""))
							JOptionPane.showMessageDialog(null,"Invalid room name","Error"
								,JOptionPane.ERROR_MESSAGE);
					}
					while (room.equals("")&&room!=null);
					
					if(!user.canCreate())
						gui.buttonCreate.setEnabled(false);
				}
				
				catch (NullPointerException nullPointer)
				{
					gui.buttonCreate.setEnabled(true);
					return;
				}
								
				if (!vectorRooms.contains(room))
				{
					//gui.buttonRemove.setEnabled(true);
					Message message=new Message(Message.codeSendCreateRoom);
					message.setString(room);
					clientThread.sendMessage(message);
				}
				else
				{
					JOptionPane.showMessageDialog(null,"Room already exists","Error",
						JOptionPane.ERROR_MESSAGE);
					gui.buttonCreate.setEnabled(true);
				}
			}
		});
		
		gui.buttonRemove.addActionListener(new ActionListener ()
		{
			public void actionPerformed(ActionEvent event)
			{
				if (gui.listRooms.getSelectedIndex()!=-1)
				{
					gui.buttonRemove.setEnabled(false);
					Message message=new Message(Message.codeSendRemoveRoom);
					message.setString((String)gui.listRooms.getSelectedValue());
					clientThread.sendMessage(message);
				}

			}
		});
		
		gui.buttonPrivate.addActionListener(new ActionListener ()
		{
			public void actionPerformed(ActionEvent event)
			{
				if((String)gui.listUsers.getSelectedValue()==null)
				{
					JOptionPane.showMessageDialog(null,"You have started private with nobody","Error",
						JOptionPane.ERROR_MESSAGE);
					return;
				}
				//gui.buttonPrivate.setEnabled(false);
				//gui.buttonUnprivate.setEnabled(true);
				privateName=(String)gui.listUsers.getSelectedValue();
				if(privateName.equals(gui.labelUser.getText()))
				{
					JOptionPane.showMessageDialog(null,"You can't start private with yourself","Error",
						JOptionPane.ERROR_MESSAGE);
					//gui.buttonPrivate.setEnabled(true);
					//gui.buttonUnprivate.setEnabled(false);
					return;
				}
				else
				{
					gui.buttonPrivate.setEnabled(false);
					gui.buttonUnprivate.setEnabled(true);
					sendPrivate=true;
					gui.labelStatus.setText("Private conversation with "+privateName+"...");
				}
			}
		});
		
		gui.buttonUnprivate.addActionListener(new ActionListener ()
		{
			public void actionPerformed(ActionEvent event)
			{
				gui.buttonPrivate.setEnabled(true);
				gui.buttonUnprivate.setEnabled(false);
				sendPrivate=false;
				gui.labelStatus.setText("");
			}
		});
		
		gui.buttonSend.addActionListener(new ActionListener ()
		{
			public void actionPerformed(ActionEvent event)
			{
				Message message;
				if (sendPrivate)
				{
					message=new Message(Message.codeSendPrivate);
					Vector vector=new Vector();
					vector.add(privateName);
					message.setVector(vector);
					
				}
				else
				{
					message=new Message(Message.codeSendMessage);
				}
				message.setString(gui.fieldMessage.getText());
				gui.fieldMessage.setText("");
				clientThread.sendMessage(message);
			}
		});
		
		gui.buttonClear.addActionListener(new ActionListener ()
		{
			public void actionPerformed(ActionEvent event)
			{
				gui.fieldMessage.setText("");
			}
		});
		
		gui.buttonTutorial.addActionListener(new ActionListener ()
		{
			public void actionPerformed(ActionEvent event)
			{
				JOptionPane.showMessageDialog(null,"This is tutorial for chat:\n"+
				"1.In order to connect, press [Connect] button,and enter your nickname\n"+
				"2.In order to disconnect, press [Disconnect] button\n"+
				"3.To start chatting, just type your message in a message box and press Enter or [Send] button\n"+
				"4.To start private conversation:\n"+
				"    Choose a nickname from list of nicknames and press [Private] button\n"+
				"    To finish private conversation just press [UnPrivate] button\n"+
				"5.To go to another room, select room from room list and press [Go to room] button\n"+
				"6.To create room of your own press [Create room] button and type the room name\n"+
				"7.To delete your room press [Remove room] button\n","Tutorial",
					JOptionPane.QUESTION_MESSAGE);
			}
		});
		
		gui.listRooms.addListSelectionListener(new ListSelectionListener ()
		{
			public void valueChanged(ListSelectionEvent event)
			{
				if (!event.getValueIsAdjusting())
					if (gui.listRooms.getSelectedIndex()!=-1)
					{
						if (((String)gui.listRooms.getSelectedValue()).equals(user.getRoom()))
							gui.buttonGoto.setEnabled(false);
						else
							gui.buttonGoto.setEnabled(true);
							
						gui.listUsers.setListData((Vector)hashRooms.get(
							(String)gui.listRooms.getSelectedValue()));
						if (user.getCreated().contains((String)gui.listRooms.getSelectedValue()))
							gui.buttonRemove.setEnabled(true);
						else
							gui.buttonRemove.setEnabled(false);
						gui.updateUI();
					}
			}
		});
		
		gui.listUsers.addListSelectionListener(new ListSelectionListener ()
		{
			public void valueChanged(ListSelectionEvent event)
			{
				if (!event.getValueIsAdjusting())
					if (gui.listRooms.getSelectedIndex()!=-1)
					{
						if (((String)gui.listRooms.getSelectedValue()).equals(user.getName()))
						{
							gui.buttonPrivate.setEnabled(false);
							gui.buttonUnprivate.setEnabled(false);
						}
					}
					else
					{
						gui.buttonPrivate.setEnabled(false);
						gui.buttonUnprivate.setEnabled(false);
					}
			}
		});
	}
	
	public void setVectorRooms(Vector vector)
	{
		vectorRooms=vector;
		vectorRooms.remove("All Rooms");
		gui.listRooms.setListData(vector);
		gui.listRooms.setSelectedIndex(0);
		gui.buttonUnprivate.setEnabled(false);
		gui.updateUI();
	}
	
	public void setHashRooms(Hashtable hash)
	{
		hashRooms=hash;
		hashRooms.remove("All Rooms");
	}
	
	public void addNewUser(String user)
	{
		Vector vector=(Vector)hashRooms.get("Main Room");
		vector.add(user);
		gui.listUsers.setListData(vector);
		gui.updateUI();
	}
	
	public void addRoom(String room)
	{
		//gui.buttonCreate.setEnabled(false);
		vectorRooms.add(room);
		//System.out.println(vectorRooms);
		hashRooms.put(room,new Vector());
		gui.listRooms.setListData(vectorRooms);
		gui.updateUI();
	}
	
	public void removeRoom(String room)
	{
		//gui.buttonCreate.setEnabled(true);
		vectorRooms.remove(room);
		hashRooms.remove(room);
		gui.listRooms.setListData(vectorRooms);
		gui.updateUI();
		System.out.println(gui.listRooms.getSelectedIndex());
		if (gui.listRooms.getSelectedIndex()==-1)
			gui.buttonRemove.setEnabled(false);
		else
			gui.buttonRemove.setEnabled(true);
		if(user.canCreate())
			gui.buttonCreate.setEnabled(true);
	}
	
	public void moveUser(String userName,String room)
	{
		Vector vector;
		boolean flag=false;
		for (int i=0; i<vectorRooms.size()&&!flag; i++)
		{
			vector=(Vector)hashRooms.get((String)vectorRooms.elementAt(i));
			System.out.println(vector);
			if (vector.contains(userName))
			{
				vector.remove(userName);
				hashRooms.put((String)vectorRooms.elementAt(i),vector);
				System.out.println(vector);
				vector=(Vector)hashRooms.get(room);
				vector.add(userName);
				System.out.println(vector);
				hashRooms.put(room,vector);
				flag=true;
				gui.listUsers.setListData(vector);
			}
		}
		gui.updateUI();
	}
	
	public void resetAll()
	{
		gui.buttonConnect.setEnabled(true);
		gui.buttonDisconnect.setEnabled(false);
		gui.labelRoom.setText("");
		gui.labelUser.setText("");
		gui.labelStatus.setText("Client disconnected ...");
		setDefaults(false);
		hashRooms.clear();
		vectorRooms.removeAllElements();
	 	sendPrivate=false;
	 	gui.updateUI();
	}
}
