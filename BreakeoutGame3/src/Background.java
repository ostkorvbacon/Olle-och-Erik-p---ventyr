import wheels.users.*;
import java.util.concurrent.TimeUnit;
	

public class Background extends Frame
{
	static final int SIZE = 20000;

	private Rectangle _background;
	
	public Background() throws InterruptedException
	{
		_background = new Rectangle(java.awt.Color.pink);
		_background.setSize(SIZE, SIZE);

		_background.setLocation(0,0);
		
		Ball _ball=new Ball(350,400);
		Bat bat=new Bat(310,450);
		new Edges();
		brick[] b =new brick[14];
		brick[] b2 =new brick[14];
		for (int i=0;i<14;i++) 
			{
				b[i]=new brick(1+50*i,50,1);
				
			}
		for (int i=0;i<14;i++) 
		{
			b2[i]=new brick(1+50*i,100,2);
			
		}
		
		while (true/*_ball.intersectsE()*/)
		{
		
			_ball.move(5);
			
			TimeUnit.MILLISECONDS.sleep(10);
			
			_ball.intersects(b);
			_ball.intersects(b2);
			_ball.intersectsbat(bat);
			
		}
		
	}
}
