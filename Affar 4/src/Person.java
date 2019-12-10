//Modell för kunder med metoder för att komma åt deras information

public class Person 
{	
	private String _namn;
	private String _nrvar;
	
	public Person(String n,String v)
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
	public String get_nrvar() 
	{
		return _nrvar;
	}

}