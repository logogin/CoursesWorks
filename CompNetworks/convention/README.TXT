instructions for running the convention project
**************************************************************
databases
****************************************************************************
i shall connect to a database named forum(create if does not exist...)
here is a list of the tables you have to add to the database...:

create table forum_msg(pid varchar(3) , id varchar(3) , name varchar(20) , headline varchar(30) , message varchar(100))


create table msgboard( name varchar(20) , email varchar(30) , message varchar(100))

create table participants( name varchar(20) , email varchar(30) ,cardType varchar(20),cardNum varchar(20),usrname varchar(20),psswd varchar(20))


create table presenters( name varchar(20) , email varchar(30) ,subject varchar(100),link varchar(50),notes varchar(250),usrname varchar(20),psswd varchar(20))


***************************************************************************
key for ssl...:
***************************************************************************
change the settings in your server.xml file to enable ssl and run the following...
%JAVA_HOME%\bin\keytool -genkey -alias tomcat -keyalg RSA
****************************************************************************
server for the chat:
***************************************************************************
run from the convention/java-src folder the kawa project of server.kpx
use the chat via IE ...
****************************************************************************
administrator's password:
****************************************************************************
the current authoritization is for who have the 'tomcat' role...
this means that the default for administeration entrence is
user:tomcat   password:tomcat

this is defined in the web.xml file of the convention project and may be modified according to your desires...
in the .../tomcat/conf folder you may specify a user who is a'tomcat'

   


