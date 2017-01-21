
import java.awt.*;
import javax.swing.*;
import javax.swing.border.*;
import java.io.*;
import java.net.*;
import java.awt.event.*;

public class ServerGUI extends JPanel 
{
	protected JButton buttonStart=new JButton("Start");
	protected JButton buttonStop=new JButton("Stop");
	protected JLabel labelChat=new JLabel("Chat messages");
	protected JLabel labelSystem=new JLabel("System messages");
	protected JTextField labelRoom=new JTextField();
	protected JTextArea areaChat=new JTextArea(8,40);
	protected JTextArea areaSystem=new JTextArea(8,40);
	protected JLabel labelStatus=new JLabel();
	protected JList listRooms=new JList();
	protected JList listUsers=new JList();
	
	public ServerGUI()
	{
		super();
		setLayout(new BorderLayout());
	
		JPanel panelStart=new JPanel();
		panelStart.add(buttonStart);
		panelStart.add(buttonStop);
			
		Box boxChat=new Box(BoxLayout.Y_AXIS);
		boxChat.add(labelChat);
		areaChat.setEditable(false);
		areaChat.setWrapStyleWord(true);
		areaChat.setLineWrap(true);
		boxChat.add(new JScrollPane(areaChat,JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED,
							JScrollPane.HORIZONTAL_SCROLLBAR_NEVER));
							
		Box boxRoom=new Box(BoxLayout.X_AXIS);
		boxRoom.add(new JLabel(" Room being watched: "));
		labelRoom.setEditable(false);
		boxRoom.add(labelRoom);
		
		Box boxLabels=new Box(BoxLayout.Y_AXIS);
		boxLabels.add(boxRoom);
		
		boxChat.add(boxLabels,BorderLayout.NORTH);
					
		boxChat.add(labelSystem);
		areaSystem.setEditable(false);
		areaSystem.setWrapStyleWord(true);
		areaSystem.setLineWrap(true);
		boxChat.add(new JScrollPane(areaSystem,JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED,
							JScrollPane.HORIZONTAL_SCROLLBAR_NEVER));
		
		labelStatus.setText("Not Started ...");
		labelStatus.setBorder(new BevelBorder(BevelBorder.LOWERED));
	
		Box boxLists=new Box(BoxLayout.Y_AXIS);
		listRooms.setVisibleRowCount(6);
		listRooms.setFixedCellWidth(70);
		listRooms.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		boxLists.add(new JScrollPane(listRooms,JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED,
							JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED));
				
		listUsers.setVisibleRowCount(10);
		listUsers.setFixedCellWidth(70);
		listUsers.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		boxLists.add(new JScrollPane(listUsers,JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED,
							JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED));
			
		add(panelStart,BorderLayout.NORTH);
		add(boxChat,BorderLayout.CENTER);
		add(labelStatus,BorderLayout.SOUTH);
		add(boxLists,BorderLayout.EAST);
	}
}
