import javax.swing.DefaultListModel;
import javax.swing.JList;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
//Kö objektet som används
public class Ko extends JList
{
	private JList _ko;
	public Ko() 
	{
		_ko = new JList(new DefaultListModel());			
	}	
	
	//Funktioner som anropas av knapparna
	
	//Pre:Ifylda textfält. Antalet varor är ett heltal.
	//Post:Ny Person med inmatade data.
	public static void skapa(JTextField _text1,JTextField _text2,JList _list)
	{
		try 
		{
			if (_text1.getText().isEmpty()==false && _text2.getText().isEmpty()==false )
					((DefaultListModel<Person>)_list.getModel()).addElement(new Person(_text1.getText(),(int)Integer.parseInt(_text2.getText())));	
		
			else 
			{
				JOptionPane.showMessageDialog(null, "Tom Ruta","Error", 1);	
			}
			
		} 
		catch (Exception e) 
	   {
			JOptionPane.showMessageDialog(null, "Antalet varor måste vara ett heltal","Error", 2  );	
	   }
		
	}
	
	//Pre:Person har valts
	//Post:Flyttar vald Person från en lista till en annan.
	public static void flytta(JList _list,JList _ko ) 
	{
		Integer i2 = (Integer)_list.getSelectedIndex();
		if (_list.getSelectedValue()!=null) 
		{	
			Object p=_list.getSelectedValue();
			((DefaultListModel)_ko.getModel()).addElement(p);
			((DefaultListModel)_list.getModel()).removeElementAt(i2);
		}
	}
	
	//Pre:Person finns i listan
	//Post:"Betjänar" och tar sedan bort den första Personen i listan
	public static void betjana(JList _ko)
	{
		if (_ko.getModel().getSize()!=0) 
		{
			Person p=(Person) _ko.getModel().getElementAt(0);				
			JOptionPane.showMessageDialog(null,"Kund:"+ p.get_namn() +" Antal Varor:"+ p.get_nrvar() ,"",1);
			((DefaultListModel)_ko.getModel()).removeElementAt(0);	
		}
		else 
			JOptionPane.showMessageDialog(null, "\nTom Kö\n","Title", 1);
	}
}