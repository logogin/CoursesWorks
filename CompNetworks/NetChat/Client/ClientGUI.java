import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.border.*;
import java.net.*;
import java.io.*;
import javax.swing.ImageIcon;

public class ClientGUI extends JPanel
{
	protected JButton buttonConnect=new JButton("Connect");
	protected JButton buttonDisconnect=new JButton("Disconnect");
	protected JButton buttonSend=new JButton("Send");
	protected JButton buttonClear=new JButton("Clear");
	protected JTextArea areaChat=new JTextArea(10,40);
	protected JTextField fieldMessage=new JTextField(33);
	protected JLabel labelStatus=new JLabel();
	protected JTextField labelRoom=new JTextField();
	protected JTextField labelUser=new JTextField();
	protected JList listRooms=new JList();
	protected JList listUsers=new JList();
	protected JButton buttonGoto=new JButton("Go to room");
	protected JButton buttonPrivate=new JButton("Private");
	protected JButton buttonUnprivate=new JButton("UnPrivate");
	protected JButton buttonCreate=new JButton("Create room");
	protected JButton buttonRemove=new JButton("Remove room");
	protected JButton buttonTutorial=new JButton("Tutorial");
		
	public ClientGUI()
	{
		super();
		setLayout(new BorderLayout());
		
		JPanel panelConnect=new JPanel();
		panelConnect.add(buttonConnect);
		buttonDisconnect.setEnabled(false);
		panelConnect.add(buttonDisconnect);
		panelConnect.add(buttonTutorial);
		
		JPanel panelChat=new JPanel(new BorderLayout());
		areaChat.setEditable(false);
		areaChat.setWrapStyleWord(true);
		areaChat.setLineWrap(true);
			
		panelChat.add(new JScrollPane(areaChat,JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED,
								JScrollPane.HORIZONTAL_SCROLLBAR_NEVER),BorderLayout.CENTER);
		
		Box boxMessage=new Box(BoxLayout.X_AXIS);
		boxMessage.add(fieldMessage);
		JPanel panelSend=new JPanel(new FlowLayout(FlowLayout.CENTER,0,0));
		panelSend.add(buttonSend);
		panelSend.add(buttonClear);
		boxMessage.add(panelSend);
		panelChat.add(boxMessage,BorderLayout.SOUTH);
	
		labelStatus.setText("Client disconnected ... ");
		labelStatus.setBorder(new BevelBorder(BevelBorder.LOWERED));
		
		JPanel panelLists=new JPanel(new BorderLayout());
		listRooms.setVisibleRowCount(4);
		listRooms.setFixedCellWidth(70);
		listRooms.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		JPanel panelRooms=new JPanel(new BorderLayout());
		JPanel panelGoto=new JPanel(new FlowLayout(FlowLayout.CENTER,5,0));
		panelGoto.add(buttonGoto);
		panelRooms.add(panelGoto,BorderLayout.NORTH);
		panelRooms.add(new JScrollPane(listRooms,JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED,
						JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED),BorderLayout.CENTER);
		JPanel panelCreate=new JPanel(new FlowLayout(FlowLayout.CENTER));
		panelCreate.add(buttonCreate);
		panelCreate.add(buttonRemove);
		panelRooms.add(panelCreate,BorderLayout.SOUTH);
		
		listUsers.setVisibleRowCount(8);
		listUsers.setFixedCellWidth(70);
		listUsers.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		JPanel panelUsers=new JPanel(new BorderLayout());
		panelUsers.add(new JScrollPane(listUsers,JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED,
						JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED),BorderLayout.CENTER);
		Box boxRoom=new Box(BoxLayout.X_AXIS);
		boxRoom.add(new JLabel(" Room: "));
		labelRoom.setEditable(false);
		boxRoom.add(labelRoom);
		
		Box boxUser=new Box(BoxLayout.X_AXIS);
		boxUser.add(new JLabel(" User:   "));
		labelUser.setEditable(false);
		boxUser.add(labelUser);
		
		Box boxLabels=new Box(BoxLayout.Y_AXIS);
		boxLabels.add(boxRoom);
		boxLabels.add(boxUser);
		panelUsers.add(boxLabels,BorderLayout.NORTH);
		
		JPanel panelPrivate=new JPanel(new FlowLayout(FlowLayout.CENTER,5,0));
		panelPrivate.add(buttonPrivate);
		panelPrivate.add(buttonUnprivate);
		panelUsers.add(panelPrivate,BorderLayout.SOUTH);
				
		panelLists.add(panelRooms,BorderLayout.NORTH);
		panelLists.add(panelUsers,BorderLayout.CENTER);
		
		add(panelConnect,BorderLayout.NORTH);
		add(panelChat,BorderLayout.CENTER);
		add(labelStatus,BorderLayout.SOUTH);
		add(panelLists,BorderLayout.EAST);
	}
}