import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JOptionPane;

import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class CButt extends JButton{
	
	
	private JTextField _text1,_text2; 
	
	private JList<Person> _list;		


	public CButt(JList<Person> list,JPanel listPanel,Ko ko) {
		super("Skapa ny person");
		_text1 = new JTextField("--Namn här--", 15);
		_text2 = new JTextField("--Antal Varor här--", 15);
		listPanel.add(_text1);
		listPanel.add(_text2);
	
		
		_list=list;
		this.addActionListener(new PrintListener());
	}
	

	private class PrintListener implements ActionListener {
		public void actionPerformed(ActionEvent e) 
		{
	
		}
	}


}
