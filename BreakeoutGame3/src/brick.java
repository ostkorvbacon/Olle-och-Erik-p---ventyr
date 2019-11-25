import wheels.users.*;

public class brick
{
	static final int WIDTH = 50, HEIGHT = 25, SPACING = 4;

	private Rectangle _brickin, _brickout;
	private int _hits;
	
	
	
	public brick(int x, int y,int hits)
	{
		_brickout = new Rectangle(java.awt.Color.black);
		_brickout.setSize(WIDTH, HEIGHT);
		_brickin = new Rectangle(java.awt.Color.blue);
		_brickin.setSize(WIDTH-SPACING, HEIGHT-SPACING);

		_brickout.setLocation(x-SPACING/2, y-SPACING/2);
		_brickin.setLocation(x, y);
		_hits=hits;
		
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
		
		_hits=1;
	}

	public void color()
		{
		
		_brickin.setColor(java.awt.Color.red);
		
		}
}


