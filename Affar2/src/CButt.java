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
	

	public CButt(JList<Person> list,JPanel listPanel) {
		super("Ny person");
		_text1 = new JTextField("", 15);
		_text2 = new JTextField("", 15);
		listPanel.add(_text1);
		listPanel.add(_text2);
		
		_list=list;
		this.addActionListener(new PrintListener());
	}
	

	private class PrintListener implements ActionListener {
		public void actionPerformed(ActionEvent e) 
		{ if (_text1.getText().isEmpty()==false && _text2.getText().isEmpty()==false)
		{
			((DefaultListModel<Person>)_list.getModel()).addElement(new Person(_text1.getText(),_text2.getText()));
		
				JOptionPane.showMessageDialog(null,"java is fun","Title",1);	
				System.out.print(Person._namn);
				System.out.print(Person._nrvar);
		}
		else 
		{
			System.out.print("\nTom Ruta\n");
		}
		
		}
	}


}
