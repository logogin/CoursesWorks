// $Id$

import java.applet.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;

public class Client extends Panel implements Runnable,ActionListener
{
  // Components for the visual display of the chat windows
  private int    port;
  private boolean connected=false;
  private String host;
  private String strnickname;
  private TextField tf = new TextField();
  private TextField tfnickname =new TextField();
  private TextArea ta = new TextArea();
  private Panel p=new Panel();
  private Button bconnect=new Button("Connect/Disconnect");
  // The socket connecting us to the server
  private Socket socket;

  // The streams we communicate to the server; these come
  // from the socket
  private DataOutputStream dout;
  private DataInputStream din;

  // Constructor
  public Client( String ihost, int iport ) {

    host=ihost;
	port=iport;
	// Set up the screen
    setLayout( new BorderLayout() );
    add( "North", tf );
    add( "Center", ta );
	bconnect.addActionListener(this);	
    p.setLayout(new BorderLayout());
    p.add("North",new Label("nickname"));
    p.add("Center",tfnickname);
	p.add("South",bconnect);
	add("South",p);  
	// We want to receive messages when someone types a line
    // and hits return, using an anonymous class as
    // a callback
    tf.addActionListener( new ActionListener() {
      public void actionPerformed( ActionEvent e ) {
        if(connected)
		   processMessage( e.getActionCommand() );
      }
    } );

  }

  // Gets called when the user types something
  private void processMessage( String message ) 
  {
    try {

      // Send it to the server
      dout.writeUTF( /*strnickname+":"+*/message );

      // Clear out text input field
      tf.setText( "" );
    } catch( IOException ie ) { System.out.println( ie ); }
  }

  // Background thread runs this: show messages from other window
  public void run() {
    try {

      // Receive messages one-by-one, forever
      while (true) {

        // Get the next message
        String message = din.readUTF();

        // Print it to our text window
        ta.append( message+"\n" );
      }
    } catch( IOException ie ) { System.out.println( ie ); }
  }
  public void actionPerformed(ActionEvent e)
  { 
   if (connected)
   {		
	try 
	  { 
	    socket.close();
		connected=false;
		tfnickname.setText("");
      } catch( IOException ie ) 
	  { System.out.println( "Error closing "+socket );
        ie.printStackTrace();
      }
	}
	else
	{try
	 {
		socket = new Socket( host, port );
      // We got a connection!  Tell the world
      // Let's grab the streams and create DataInput/Output streams
      // from them
        din = new DataInputStream( socket.getInputStream() );
        dout = new DataOutputStream( socket.getOutputStream() );
        strnickname=tfnickname.getText();
	    dout.writeUTF(strnickname);
	    if((din.readUTF()).equals("ok"))
	    {
	      System.out.println( strnickname+" connected to "+socket );
	      connected=true;
	      // Start a background thread for receiving messages
		  new Thread( this ).start();
	    }
	  else  ta.append("Please enter a valid nickname!!!\n");
		
	 }catch( IOException ie ) { System.out.println( ie ); }		
	}
	    
	
  }//end of actionPerformed...
  
}//end of class...
