public class Person 
{	
	private String _namn;
	private String _nrvar;
	
	public Person(String n,String v)
	{
		_namn=n;
		_nrvar=v;			
	}

	public String get_namn() 
	{
		return _namn;
	}

	public void set_namn(String _namn) 
	{
		this._namn = _namn;
	}

	public String get_nrvar() 
	{
		return _nrvar;
	}

	public void set_nrvar(String _nrvar) 
	{
		this._nrvar = _nrvar;
	}	
}