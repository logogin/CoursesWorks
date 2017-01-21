// $Id$

import java.io.*;
import java.net.*;
import java.util.*;

public class Server
{
  // The ServerSocket we'll use for accepting new connections
  private ServerSocket ss;
  private Vector vnicknames=new Vector();
  // A mapping from sockets to DataOutputStreams.  This will
  // help us avoid having to create a DataOutputStream each time
  // we want to write to a stream.
  private Hashtable outputStreams = new Hashtable();

  // Constructor and while-accept loop all in one.
  public Server( int port ) throws IOException {

    // All we have to do is listen
    listen( port );
  }

  private void listen( int port ) throws IOException 
  {
	String tempstr;
    // Create the ServerSocket
    ss = new ServerSocket( port );

    
    System.out.println( "Listening on "+ss );

    // Keep accepting connections forever
    while (true) {

      // Grab the next incoming connection
      Socket s = ss.accept();
      // Tell the world we've got it
      // Create a DataOutputStream for writing data to the
      // other side
      DataOutputStream dout = new DataOutputStream( s.getOutputStream() );
	  DataInputStream din = new DataInputStream( s.getInputStream() );
      if(!(vnicknames.contains((tempstr=din.readUTF()))||
	       tempstr.equals("")))
	  { dout.writeUTF("ok");
	  	vnicknames.addElement(tempstr);  
	  // Save this stream so we don't need to make it again
        outputStreams.put( s, dout );
      
	  // Tell the world we're ready to go
	    System.out.println(tempstr+ " Connected from "+s );
      // Create a new thread for this connection, and then forget
      // about it
        new ServerThread( this, s,tempstr );
	  }
	  else dout.writeUTF("not ok!!!");
    }
  }

  // Get an enumeration of all the OutputStreams, one for each client
  // connected to us
  Enumeration getOutputStreams() {
    return outputStreams.elements();
  }

  // Send a message to all clients (utility routine)
  void sendToAll( String message ) {

    // We synchronize on this because another thread might be
    // calling removeConnection() and this would screw us up
    // as we tried to walk through the list
    try {
       //Write to file
           byte b[] = message.getBytes();
           String outputFileName = System.getProperty("user.home",
                                 File.separatorChar + "home" + 
                                 File.separatorChar + "zelda") + 
                                 File.separatorChar + "chat_log.txt";
           File outputFile = new File(outputFileName);
           RandomAccessFile out = new RandomAccessFile(outputFile, "rw");
           synchronized(out)
          {
            out.seek(outputFile.length());
            out.write(b);
      //Write a new line (NL) to the file.
            out.writeByte('\n');
            out.close();
          }
    	} catch(java.io.IOException e) {
         System.out.println(e.toString());
       }
	
    
	synchronized( outputStreams ) {

      // For each client ...
      for (Enumeration e = getOutputStreams(); e.hasMoreElements(); ) {

        // ... get the output stream ...
        DataOutputStream dout = (DataOutputStream)e.nextElement();

        // ... and send the message
        try {
          dout.writeUTF( message );
        } catch( IOException ie ) { System.out.println( ie ); }
      }//end for
    }//end synchronized...
  }

  // Remove a socket, and it's corresponding output stream, from our
  // list.  This is usually called by a connection thread that has
  // discovered that the connectin to the client is dead.
  void removeConnection( Socket s,String nickname ) {

    // Synchronize so we don't mess up sendToAll() while it walks
    // down the list of all output streamsa
    synchronized( outputStreams ) {

      // Tell the world
      System.out.println( "Removing connection to "+s );

      // Remove it from our hashtable/list
      outputStreams.remove( s );

      // Make sure it's closed
      try {
        s.close();
      } catch( IOException ie ) {
        System.out.println( "Error closing "+s );
        ie.printStackTrace();
      }
    }//end of synchronization interval...
    vnicknames.removeElement(nickname);
  }
  // Main routine
  // Usage: java Server <port>
  static public void main( String args[] ) throws Exception {

    // Get the port # from the command line
    int port = 8001;

    // Create a Server object, which will automatically begin
    // accepting connections.
    new Server( port );
  }
}
