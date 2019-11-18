import wheels.users.*;

public class brick
{
	static final int WIDTH = 50, HEIGHT = 25, SPACING = 4;

	private Rectangle _brickin, _brickout;
	
	public brick(int x, int y)
	{
		_brickout = new Rectangle(java.awt.Color.black);
		_brickout.setSize(WIDTH, HEIGHT);
		_brickin = new Rectangle(java.awt.Color.blue);
		_brickin.setSize(WIDTH-SPACING, HEIGHT-SPACING);

		_brickout.setLocation(x-SPACING/2, y-SPACING/2);
		_brickin.setLocation(x, y);
	}
}
