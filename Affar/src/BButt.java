import javax.swing.*;
import java.awt.event.*;

public class BButt extends JButton
{
	private JList _ko;    //peer object
	
	public BButt (JList ko,String s ) {
		super(s);
		_ko=ko;
		this.addActionListener(new RemoveListener());
	}
	
	private class RemoveListener implements ActionListener {
		public void actionPerformed(ActionEvent e) 
		{
			
			if (_ko.getModel().getSize()!=0) 
			{
				Person p=(Person) _ko.getModel().getElementAt(0);
				//Person p2=(Person) _ko.getModel().getElementAt(1);
				System.out.print( p.get_namn() );
				//System.out.print( p2.get_namn());
				
				JOptionPane.showMessageDialog(null,"Kund:"+ p.get_namn() +" Antal Varor:"+ p.get_nrvar() ,"",1);
				((DefaultListModel)_ko.getModel()).removeElementAt(0);
				
			}
			
			else JOptionPane.showMessageDialog(null, "\nTom Ko\n","Title", 1);
		}
	}
}
