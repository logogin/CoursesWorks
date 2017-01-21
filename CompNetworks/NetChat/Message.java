import java.util.*;
import java.io.Serializable;

public class Message implements Serializable
{
	final static byte codeSendUserName=1;
	final static byte codeSendUserNameResponse=2;
	final static byte codeSendAddNewUser=3;
	final static byte codeSendMoveToRoom=4;
	final static byte codeSendMoveToRoomResponse=5;
	final static byte codeSendCreateRoom=6;
	final static byte codeSendCreateRoomResponse=7;
	final static byte codeSendRemoveRoom=8;
	final static byte codeSendRemoveRoomResponse=9;
	final static byte codeSendMessage=10;
	final static byte codeSendPrivate=11;
	final static byte codeSendUpdateTables=12;
	final static byte codeRemoveUser=13;
	
	protected byte byteCode;
	protected boolean bFailure;
	protected String stringMessage;
	protected Hashtable hashList;
	protected Vector vector;

	public Message()
	{
		
	}
	
	public Message(byte code)
	{
		byteCode = code;
	}
	
	public void setCode(byte code)
	{
		byteCode = code;
	}
	
	public byte getCode()
	{
		return byteCode;
	}
	
	public void setString(String string)
	{
		stringMessage = string;
	} 
	
	public String getString()
	{
		return stringMessage;
	}
	
	public boolean isFailure()
	{
		return bFailure;
	}
	
	public void setFailure(boolean failure)
	{
		bFailure = failure;
	}
	
	public void setHashList(Hashtable hash)
	{
		hashList=hash;	
	}
	
	public Hashtable getHashList()
	{
		return hashList;	
	}
	
	public void setVector(Vector vector)
	{
		this.vector=vector;	
	}
	
	public Vector getVector()
	{
		return vector;	
	}
}