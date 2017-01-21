
import java.applet.Applet;
import java.awt.*;
public class AppletExample extends Applet{
private String param1;
public void init()
{
	setSize(300,100);
	param1=this.getParameter("param1");
}
public void paint (Graphics page)
{
page.drawString("Yoy passed the following parameter: "+param1 ,30,50);
}
}

