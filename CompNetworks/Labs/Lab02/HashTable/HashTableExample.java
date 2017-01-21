import java.util.*;
import java.io.*;

public class HashTableExample
{
	public static void main(String args[])
	{
Hashtable table = new Hashtable();

//Insrting new Values
table.put("apple","red");
table.put("kiwi","green");
table.put("mango","yellow");

//Printing Inner object form Table
System.out.println(table.get("mango"));

//Removing Element
table.remove("mango");

//printing all HashTable List
for (Enumeration e = table.elements() ; e.hasMoreElements() ;) 
         System.out.println(e.nextElement());
		 
	}
}
