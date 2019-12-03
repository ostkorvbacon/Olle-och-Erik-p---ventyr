
import javax.swing.*;
import java.awt.event.*;

public class MoveButt extends JButton {
	private JList _list,_ko;    //peer object
	
	public MoveButt(JList aList,String s,JList ko ) {
		super(s);
		_list = aList;
		_ko=ko;
		this.addActionListener(new RemoveListener());
	}
	
	private class RemoveListener implements ActionListener {
		public void actionPerformed(ActionEvent e) 
		{
			Integer i = (Integer)_list.getSelectedIndex();
			if (_list.getSelectedValue()!=null) {
				
				Object p=_list.getSelectedValue();
				((DefaultListModel)_ko.getModel()).addElement(p);
				((DefaultListModel)_list.getModel()).removeElementAt(i);
			}
		}
	}
}