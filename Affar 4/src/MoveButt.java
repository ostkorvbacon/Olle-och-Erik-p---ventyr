import javax.swing.*;
import java.awt.event.*;

public class MoveButt extends JButton 
{
	private JList _list,_ko;   //Variabler som anväds för att lagra data som är nödvändig för metod-anrop.
	
	public MoveButt(JList aList,String s,JList ko ) 
	{
		super(s);
		_list = aList;
		_ko=ko;
		this.addActionListener(new RemoveListener());
	}
	//Specifik lysnare till knappen
	private class RemoveListener implements ActionListener 
	{	//Pre:true
		//Post:Anropar metod som flyttar mellan listor när knappen aktiveras.
		public void actionPerformed(ActionEvent e) 
		{
		
			ControlPanel.flytta(_list,_ko);
		}
	}
}