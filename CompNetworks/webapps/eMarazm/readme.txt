Installation notes for eDucation Project.
-----------------------------------------

To install eDucation project you must:

1. Copy the project directory into $CATALINA_HOME\webapps.
2. Copy server.xml into $CATALINA_HOME\conf.
3. Copy the Database eMarazm into SQL\Data.
4. Start MySQL service.
5. Start Tomcat server.
6. Open your browser and enter to: https://localhost:8443/eMarazm
7. To generate keystore file use keygen.bat
8. To change SMTP host use parameter "smtpHost" in web.xml

After you opened the site homepage, you'll be asked for ID and password.
ID is the user's ID that user enters during the registration.
You can logon as: administrator, lector or student.
After you have logged on, you have several options.
For each group of users there is a different options.

Administartors:
---------------
1. Delete test.
2. Change personal info.
3. Show all users.
4. View messages from different users.
5. Register new lector.
6. View system logs.
7. SQL console, where the admin can look at all users from all groups and edit the database.

Lectors:
--------
1. Change personal info.
2. Show all users who made there info public.
3. View messages from different users.
4. Compose an american test in two ways: single choice or multiple choice.
5. View statistics about test, such as: who solved the test, what grade.

Students:
---------
1. Change personal info.
2. Show all users who made there info public.
3. View messages from different users.
4. Start/continue to solve test.

All users from all groups can send a messages to other users.
All users can use chat.
It is possible to send e-mail to users with public info.
--------------------------------------------------------------------------------------------

eDucation project components:
-----------------------------
servlets list:
--------------
addquestion.java   - adding question during test composition
changeinfo.java    - changing info of the user
chatboard.java
chatmessage.java
clearlog.java      - clear system log (administrators only)
composetest.java   - compose test (lectors only)
console.java       - sql console (administrators only)
deletemessage.java
deletetest.java    - delete test (administrators only)
dotest.java        
eMarazm.java       - base class
login.java
logoff.java
profile.java
register.java
sendmail.java
sendmessage.java
showtree.java
showusers.java
showwelcome.java
startcompose.java  - test composition (lectors only)
stats.java         - statistics
testinfo.java      - view statistics (lectors only)
userinfo.java
viewlog.java       - view system log (administrators only)
viewmessage.java
viewmessages.java


