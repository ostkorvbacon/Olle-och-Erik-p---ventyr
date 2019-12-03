import wheels.users.Rectangle;

public class Edges
{
	static final int GIRTH = 1, LENGHT = 700;
	private Rectangle _edgeleft, _edgeright, _edgeupp, _edgedown;
	
	public Edges()
	{
		_edgeleft = new Rectangle(java.awt.Color.black);
		_edgeleft.setSize(GIRTH, LENGHT);
		_edgeupp = new Rectangle(java.awt.Color.black);
		_edgeupp.setSize(LENGHT, GIRTH);
		_edgeright = new Rectangle(java.awt.Color.black);
		_edgeright.setSize(GIRTH, LENGHT);
		_edgedown = new Rectangle(java.awt.Color.green);
		_edgedown.setSize(LENGHT, GIRTH);
		
		_edgeleft.setLocation(0, 0);
		_edgeupp.setLocation(0, 0);
		_edgeright.setLocation(698, 0);
		_edgedown.setLocation(0, 499);


	}
}