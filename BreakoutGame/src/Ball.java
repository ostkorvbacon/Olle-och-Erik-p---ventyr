import wheels.users.*;
import java.awt.Shape; 

public class Ball
{
	static final int SIZE = 20, SPACING = 4;

	private Ellipse _ballin, _ballout;
	int yd=1;
	int xd=1;
	public int score;
	
	public Ball(int x, int y)
	{
		_ballout = new Ellipse(java.awt.Color.black);
		_ballout.setSize(SIZE, SIZE);
		_ballin = new Ellipse(java.awt.Color.red);
		_ballin.setSize(SIZE-SPACING, SIZE-SPACING);

		_ballout.setLocation(x-SPACING/2, y-SPACING/2);
		_ballin.setLocation(x, y);
	}

	public boolean intersectsE()
	{
		if (_ballout.getYLocation()>=489-SIZE) return true;
		else return false;		
	}
	
	public int intersects(brick[] b,Bat bat)
	{
		for(int i=0;i<b.length;i++) 
		{
			if (_ballout.getYLocation() >= b[i].getYLocation() &&_ballout.getYLocation() < b[i].getYLocation()+25 && _ballout.getXLocation() > b[i].getXLocation() && _ballout.getXLocation()< b[i].getXLocation()+50) 
				{
			    	yd=yd*-1;
			    	if (b[i].getS()==1) 
			    		bat.setWidth(2);
			
			    	if (b[i].Hits()==1)
			    	{
			    		b[i].setLocation(-50, -50);
			    		return 1; 
			    	}
				
			    	else 
			    	{
			    		b[i].setHits();
			    		b[i].color(b[i].Hits());
			    	}
				}
		}	
		return 0;
	}
	
	public void move(int x,int y)
	{  
		if (_ballout.getYLocation()>=499-SIZE) yd=yd*-1;
		if (_ballout.getYLocation()<=1) 	   yd=yd*-1;
		if (_ballout.getXLocation()<=1+SIZE/2) xd=xd*-1;
		if (_ballout.getXLocation()>=700-SIZE) xd=xd*-1;
			
		_ballout.setLocation(_ballout.getXLocation()+xd*x, _ballout.getYLocation()+yd*y);
		_ballin.setLocation(_ballin.getXLocation()+xd*x, _ballin.getYLocation()+yd*y);		
	}
		


	public boolean intersectsbat(Bat bat)
	{		
		if (_ballout.getYLocation()+10 >= bat.getYLocation() &&_ballout.getYLocation() < bat.getYLocation()+bat.getHeight() && _ballout.getXLocation() > bat.getXLocation() && _ballout.getXLocation()<bat.getXLocation()+bat.getWidth()) 
		{	
			yd=yd*-1;
		}
			return true;
	}


	public void setLocation(int x, int y) 
	{
		_ballout.setLocation(x-SPACING/2, y-SPACING/2);
		_ballin.setLocation(x, y);
		yd=yd*-1;
	}

}