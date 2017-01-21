import javax.swing.JOptionPane;
import java.awt.event.*;

public class InputDialog extends JOptionPane 
{
	
	public InputDialog()
	{
		super();	
		addActionListener( new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				System.out.println(getComponent(e.getID()));	
			}	
		});
	}
	
}
