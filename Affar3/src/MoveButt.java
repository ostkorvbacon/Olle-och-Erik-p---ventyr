import javax.swing.*;
import java.awt.event.*;

public class MoveButt extends JButton 
{
	private JList _list,_ko;    //peer object
	
	public MoveButt(JList aList,String s,JList ko ) 
	{
		super(s);
		_list = aList;
		_ko=ko;
		this.addActionListener(new RemoveListener());
	}
	
	private class RemoveListener implements ActionListener 
	{
		public void actionPerformed(ActionEvent e) 
		{
			Integer i2 = (Integer)_list.getSelectedIndex();
			if (_list.getSelectedValue()!=null) 
			{	
				Object p=_list.getSelectedValue();
				((DefaultListModel)_ko.getModel()).addElement(p);
				((DefaultListModel)_list.getModel()).removeElementAt(i2);
			}
			for (int i=0;i<_ko.getModel().getSize();i++)
				System.out.print("Start "+_ko.getModel().getElementAt(i)+"Slut ");
			
			System.out.print("\n");
		}
	}
}