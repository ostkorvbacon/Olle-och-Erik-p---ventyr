import wheels.users.Rectangle;

import java.awt.Point;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;


public class Bat extends Rectangle 
{
	static final int WIDTH = 100, HEIGHT = 15, SPACING = 4;
	private Point _lastMousePosition;

	private Rectangle _batout, _batin;	
	
	public Bat(int x, int y)
	{
		super(java.awt.Color.BLACK);
		_lastMousePosition = new Point();
		this.setSize(75, 15);
		this.setLocation(x, y);
		
       
		/*super(java.awt.Color.BLACK);
		_lastMousePosition = new Point();
		this.setSize(75, 15);
		this.setLocation(x, y);*/
	/*	_lastMousePosition = new Point();
		_batout = new Rectangle(java.awt.Color.black);
		_batout.setSize(WIDTH, HEIGHT);
		_batin = new Rectangle(java.awt.Color.red);
		_batin.setSize(WIDTH-SPACING, HEIGHT-SPACING);

		_batout.setLocation(x-SPACING/2, y-SPACING/2);
		_batin.setLocation(x, y);
		*/
	}

	public int getYL() {
		
		return this.getYLocation();
	}
	public int getXL() {
		
		return this.getXLocation();
	}

	public void setWidth(int i) {
			
		    this.setSize(i*WIDTH, HEIGHT);
		    
		}
	
	public void mousePressed(MouseEvent e) {
		_lastMousePosition = e.getPoint();
		
	}
	
	public void mouseDragged(MouseEvent e) {
		Point currentPoint = e.getPoint();
		int diffX = currentPoint.x - _lastMousePosition.x;
		this.setLocation(this.getXLocation() + diffX, this.getYLocation());
		_lastMousePosition = currentPoint;
	}






}

	





	
	
	



