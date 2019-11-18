import wheels.users.*;

public class Ball
{
	static final int SIZE = 20, SPACING = 4;

	private Ellipse _ballin, _ballout;
	
	public Ball(int x, int y)
	{
		_ballout = new Ellipse(java.awt.Color.black);
		_ballout.setSize(SIZE, SIZE);
		_ballin = new Ellipse(java.awt.Color.red);
		_ballin.setSize(SIZE-SPACING, SIZE-SPACING);

		_ballout.setLocation(x-SPACING/2, y-SPACING/2);
		_ballin.setLocation(x, y);
	}
}
