//Modell f�r kunder med metoder f�r att komma �t deras information

public class Person 
{	
	private String _namn;
	private int _nrvar;
	
	public Person(String n,int v)
	{
		_namn=n;
		_nrvar=v;	//Antal varor		
	}
	//Pre:true
	//Post:personens namn returneras
	public String get_namn() 
	{
		return _namn;
	}
	
		//Pre:true
		//Post:personens antal varor returneras
	public int get_nrvar() 
	{
		return _nrvar;
	}

}