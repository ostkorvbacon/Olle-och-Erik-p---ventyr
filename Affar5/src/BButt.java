import javax.swing.*;
import java.awt.event.*;

public class BButt extends JButton
{
	private JList _ko;     //Variabel som anv�ds f�r att lagra data som �r n�dv�ndig f�r metod-anrop.
	
	public BButt (JList ko,String s ) 
	{
		super(s);
		_ko=ko;
		this.addActionListener(new RemoveListener());
	}
	
	//Specifik lysnare till knappen
	private class RemoveListener implements ActionListener 
	{	//Pre:true
		//Post:Anropar metod som bej�nar personen f�rst i k�n n�r knappen aktiveras.
		public void actionPerformed(ActionEvent e) 
		{
			ControlPanel.betjana(_ko);
		}
	}
}