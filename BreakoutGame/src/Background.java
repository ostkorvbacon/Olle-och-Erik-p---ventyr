import wheels.users.*;

public class Background
{
	static final int SIZE = 20000;

	private Rectangle _background;
	
	public Background()
	{
		_background = new Rectangle(java.awt.Color.pink);
		_background.setSize(SIZE, SIZE);

		_background.setLocation(0,0);
	}
}
