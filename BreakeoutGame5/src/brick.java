import wheels.users.*;

public class brick
{
	static final int WIDTH = 50, HEIGHT = 25, SPACING = 4;

	private Rectangle _brickin, _brickout;
	private int _hits,_s;
	
	
	
	public brick(int x, int y,int hits,int s)
	{
		
		_brickout = new Rectangle(java.awt.Color.black);
		_brickout.setSize(WIDTH, HEIGHT);
		_brickin = new Rectangle(java.awt.Color.blue);
		_brickin.setSize(WIDTH-SPACING, HEIGHT-SPACING);

		_brickout.setLocation(x-SPACING/2, y-SPACING/2);
		_brickin.setLocation(x, y);
		_hits=hits;
		_s=s;
		
		
		
		if (_hits==1)
		{
			_brickin.setColor(java.awt.Color.blue);
			
		}
			
		if (_hits==2)
		{
			_brickin.setColor(java.awt.Color.green);
			
		}
			
			if (_hits==3)
			{
				_brickin.setColor(java.awt.Color.orange);
				
			}
			
			
			
		
			
			
		
		
	}

	public int getYLocation() {
	
		return _brickout.getYLocation();
	}
	public int getXLocation() {
		
		return _brickout.getXLocation();
	}

	public void setLocation(int x, int y) {
		_brickout.setLocation(x-SPACING/2, y-SPACING/2);
		_brickin.setLocation(x, y);
	}
	
	public int Hits() {
		
		return _hits;
	}

public void setHits() {
		
		_hits=_hits-1;
	

}

	public void color(int a)
		{
		if (a==1)
		_brickin.setColor(java.awt.Color.blue);
		
		if (a==2)
			_brickin.setColor(java.awt.Color.green);
		
		if (a==3)
			_brickin.setColor(java.awt.Color.orange);
		
		if (a==4)
		_brickin.setColor(java.awt.Color.yellow);
	
	}
	
	public int getS() 
	
	{
		return _s;
	}
	
	

	



}


