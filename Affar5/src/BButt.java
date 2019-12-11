import javax.swing.*;
import java.awt.event.*;

public class BButt extends JButton
{
	private JList _ko;     //Variabel som anväds för att lagra data som är nödvändig för metod-anrop.
	
	public BButt (JList ko,String s ) 
	{
		super(s);
		_ko=ko;
		this.addActionListener(new RemoveListener());
	}
	
	//Specifik lysnare till knappen
	private class RemoveListener implements ActionListener 
	{	//Pre:true
		//Post:Anropar metod som bejänar personen först i kön när knappen aktiveras.
		public void actionPerformed(ActionEvent e) 
		{
			ControlPanel.betjana(_ko);
		}
	}
}