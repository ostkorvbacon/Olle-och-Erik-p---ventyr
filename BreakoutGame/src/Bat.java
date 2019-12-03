import wheels.users.Rectangle;

import java.awt.Color;
import java.awt.Point;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;


public class Bat extends Rectangle 
{
	static final int WIDTH = 100, HEIGHT = 15, SPACING = 2;
	private Point _lastMousePosition;
	private Rectangle _batout, _batin;	
	
	public Bat(int x, int y)
	{
		super(java.awt.Color.RED);
		_lastMousePosition = new Point();
		this.setSize(75, 15);
		this.setLocation(x, y);
		this.setOutline(java.awt.Color.black, SPACING);

	}
	public void setOutline (java.awt.Color color, int thickness) 
	{
		this.setFrameColor(color);
		this.setFrameThickness(thickness);
	}
	public int getYL() 
	{
		return this.getYLocation();
	}
	public int getXL() 
	{	
		return this.getXLocation();
	}

	public void setWidth(int i) 
	{		
		this.setSize(i*WIDTH, HEIGHT);		    
	}
	
	public void mousePressed(MouseEvent e) 
	{
		_lastMousePosition = e.getPoint();	
	}
	
	public void mouseDragged(MouseEvent e) 
	{
		Point currentPoint = e.getPoint();
		int diffX = currentPoint.x - _lastMousePosition.x;
		this.setLocation(this.getXLocation() + diffX, this.getYLocation());
		_lastMousePosition = currentPoint;
	}
}