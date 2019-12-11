import java.awt.*;
import java.util.*;
import javax.swing.*;

public class ControlPanel extends JPanel 
{	//Variabler som krävs.
	private JList  _list,_ko1,_ko2;
	private JButton _add, _mko1,_mko2,_bko1,_bko2;
	private JPanel _listPanel, _buttonPanel,_textp,_kop1,_kop2;
	public JTextField _text1,_text2;
	//private JLabel k1,k2;

	//Skapar komponenter i fönstret.
	public ControlPanel() 
	{
		super(new BorderLayout());
		_list = new JList<Person>(new DefaultListModel<Person>());
		_ko1 =new JList<Person>(new DefaultListModel<Person>());
		_ko2 =new JList<Person>(new DefaultListModel<Person>());
		_list.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		_listPanel = new JPanel();
		_textp=new JPanel();
		_kop1=new JPanel();
		_kop2=new JPanel();
			
		_listPanel.add(_list);
		_kop1.add(_ko1,BorderLayout.SOUTH);
		_kop1.add(new JLabel("Kö 1"), BorderLayout.NORTH);
		
		_kop2.add(_ko2,BorderLayout.SOUTH);
		_kop2.add(new JLabel("Kö 2"),BorderLayout.NORTH);
		
		_add= new CButt(_list,_textp);
		_mko1= new MoveButt(_list,"Flytta till Kö 1",_ko1);
		_mko2= new MoveButt(_list,"Flytta till Kö 2",_ko2);
		_bko1= new BButt(_ko1,"Betjäna kö 1");
		_bko2= new BButt(_ko2,"Betjäna kö 2");
					
		_buttonPanel = new JPanel();
		_buttonPanel.add(_mko1);
		_buttonPanel.add(_mko2);
		_buttonPanel.add(_add);
		_buttonPanel.add(_bko1);
		_buttonPanel.add(_bko2);
		
		this.add(_listPanel, BorderLayout.CENTER);
		this.add(_buttonPanel, BorderLayout.SOUTH);
		this.add(_textp, BorderLayout.NORTH);
		this.add(_kop1, BorderLayout.WEST);
		this.add(_kop2, BorderLayout.EAST);
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