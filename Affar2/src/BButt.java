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
			
			if (_ko.getModel().getElementAt(0)!=null) 
			{
				Person p=(Person) _ko.getModel().getElementAt(0);
				JOptionPane.showMessageDialog(null,"Kund:"+p._namn+" Antal Varor:"+p._nrvar,"",1);
				((DefaultListModel)_ko.getModel()).removeElementAt(0);
				
			}
		}
	}
}
