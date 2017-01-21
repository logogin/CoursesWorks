import java.net.*;

public class DNS{

  public static void main(String[] args){

         try{

            System.out.println(
                  "Get and display IP address of URL by name");
            InetAddress address = InetAddress.getByName(
                                    "www2.austin.cc.tx.us");
            System.out.println(address);
            

            System.out.println(
                       "Do reverse lookup on the IP address");
               //Extract the IP address from the string to the right
               // of the /.  Then provide the IP address as a string
               // to the getByName() method.
           int temp = address.toString().indexOf('/');
           address = InetAddress.getByName(
                          address.toString().substring(temp+1));
					
           System.out.println("Address :"+address);

System.out.println("Printing all IP addresses of hosts");
   InetAddress   addresses[] = InetAddress.getAllByName("www.yahoo.com");
for(int i=0;i<addresses.length; i++) 
{
	  System.out.println(addresses[i]);
}

           System.out.println(
                 "Get and display current IP address of LocalHost");
           address = InetAddress.getLocalHost();
           System.out.println(address);


           System.out.println(
                             "Do reverse lookup on current " + 
                                   "IP address of LocalHost");
          temp = address.toString().indexOf('/');
          address = InetAddress.getByName(
                          address.toString().substring(temp+1));
          System.out.println(address);

          System.out.println(
                  "Get and display current name of LocalHost");
          System.out.println(address.getHostName());

          System.out.println(
                 "Get and display current IP address of LocalHost");
              //Get IP address as an array of bytes.
          byte[] bytes = address.getAddress();
              //Convert IP address bytes to unsigned values 
              // and display separated by spaces.
           for(int cnt = 0; cnt < bytes.length; cnt++){
                      int uByte = 
                       bytes[cnt] < 0 ? bytes[cnt] + 256 : bytes[cnt];
               System.out.print(uByte + " ");
               }//end for loop
          System.out.println();
         }// end  try  ??
         
         
         catch(UnknownHostException e){
             System.out.println(e);
             System.out.println("Must be online to run properly.");
         }//end catch

  }//end main

}//end class 