
import java.net.*;
import java.io.*;
import java.util.*;
import javax.swing.JOptionPane;

public class ServerThread extends Thread
{
	protected Server server;
	protected ServerSocket socketServer;
	protected int port;
	protected boolean bFirst=true;
	
	public ServerThread(Server server)
	{
		this.server=server;
		for (int i=0; i<server.vectorRooms.size(); i++)
			server.hashRooms.put((String)server.vectorRooms.elementAt(i),new Vector());	
			
		server.gui.listRooms.setListData(server.vectorRooms);
		server.gui.updateUI();
		server.gui.listRooms.clearSelection();
		server.gui.listRooms.setSelectedIndex(1);
		server.bAllRooms=false;
	}
	
	public void startServer(int port)
	{
		this.port=port;
		start();
	}
	
	public void stopServer()
	{
		try
		{
			socketServer.close();
			server.closeAllConnections();
			server.gui.labelStatus.setText("Server stopped...");
			server.gui.buttonStart.setEnabled(true);
		}
		
		catch (IOException ioException)
		{
			ioException.printStackTrace();
		}
	}
	
	public void run()
	{
		try
		{
			socketServer=new ServerSocket(port);
			server.gui.labelStatus.setText("Server started...");
			server.gui.buttonStop.setEnabled(true);
			do
			{
				Socket socket=socketServer.accept();
				server.gui.areaSystem.append("Got new connection from "
					+socket.getInetAddress().getHostAddress()+":"+
					socket.getPort()+"\n");
				SocketThread socketThread=new SocketThread(server,socket);
			}
			while (true);
		}
		catch (BindException bindException)
		{
			bindException.printStackTrace();
			JOptionPane.showMessageDialog(null,"Address already in use ...","Error",
				JOptionPane.ERROR_MESSAGE);
			server.resetAll();
		}
		
		catch (SocketException socketException)
		{
			socketException.printStackTrace();
			server.resetAll();
		}
		
		catch (IOException ioException)
		{
			ioException.printStackTrace();
			JOptionPane.showMessageDialog(null,"Error starting server ...","Error",
				JOptionPane.ERROR_MESSAGE);
			server.resetAll();
		}
	}
}
