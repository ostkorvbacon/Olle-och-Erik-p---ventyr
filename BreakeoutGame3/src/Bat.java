import wheels.users.Rectangle;

public class Bat
{
	static final int WIDTH = 100, HEIGHT = 15, SPACING = 4;

	private Rectangle _batout, _batin;	
	
	public Bat(int x, int y)
	{
		_batout = new Rectangle(java.awt.Color.black);
		_batout.setSize(WIDTH, HEIGHT);
		_batin = new Rectangle(java.awt.Color.red);
		_batin.setSize(WIDTH-SPACING, HEIGHT-SPACING);

		_batout.setLocation(x-SPACING/2, y-SPACING/2);
		_batin.setLocation(x, y);
	}

	public int getYLocation() {
		
		return _batout.getYLocation();
	}
	public int getXLocation() {
		
		return _batout.getXLocation();
	}



}
