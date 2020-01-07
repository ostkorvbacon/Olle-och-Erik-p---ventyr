import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JOptionPane;

import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class CButt extends JButton
{
	private JTextField _text1,_text2; //Variabel som anv�ds f�r att lagra data som �r n�dv�ndig f�r metod-anrop och skapande av JTextField.	
	private JList<Person> _list;	

	//Skapar textf�lt att l�sa in data fr�n (och knappen s� klart).
	public CButt(JList<Person> list,JPanel listPanel) 
	{
		super("Skapa ny person");
		_text1 = new JTextField("--Namn h�r--", 15);
		_text2 = new JTextField("--Antal Varor h�r--", 15);
		listPanel.add(_text1);
		listPanel.add(_text2);
	
		_list=list;
		this.addActionListener(new PrintListener());
	}
	//Specifik lysnare till knappen
	private class PrintListener implements ActionListener 
	{	//Pre:true
		//Post:Anropar metod som skapar en ny person.
		public void actionPerformed(ActionEvent e) 
		{
			Ko.skapa(_text1, _text2, _list);
		}
	}


}
