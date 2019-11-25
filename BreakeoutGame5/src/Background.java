import wheels.users.*;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.concurrent.TimeUnit;
	

public class Background extends Frame implements KeyListener
{
	static final int SIZE = 20000;

	private Rectangle _background;
	int score=0,hp=3;
	
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
		brick[] b3 =new brick[4];
		
		for (int i=0;i<14;i++) 
			{
				b[i]=new brick(1+50*i,70,1,0);
				
			}
		for (int i=0;i<14;i++) 
		{
			b2[i]=new brick(1+50*i,20,3,0);
			
		}
		
		for (int i=0;i<b3.length;i++) 
		{
			b3[i]=new brick(25+200*i,45,2,1);
			b3[i].color(4);
			
		}
		//bat.setWidth(1);
		while (hp>0)
		{
			TimeUnit.MILLISECONDS.sleep(10);
			_ball.move(-5);
		
			if (_ball.intersectsE()==true) 
			{ 
				hp--;
				_ball.setLocation(350, 250);
				bat.setWidth(1);
				System.out.println("Poang: "+score+" Bollar: "+hp);
				TimeUnit.SECONDS.sleep(1);
			}
			
			
			if(_ball.intersects(b,bat)==1) 
			{
			score=score+1;
			
			System.out.println("Poang: "+score+" Bollar: "+hp);
			}
			
			if(_ball.intersects(b2,bat)==1) 
			{
			score=score+3;
			
			System.out.println("Poang: "+score+" Bollar: "+hp);
			}
			
			if(_ball.intersects(b3,bat)==1) 
			{
				
				score=score+1;
			System.out.println("Poang: "+score+" Bollar: "+hp);
			}

			_ball.intersectsbat(bat);
			
			
		}
		System.out.println("Game Over");
		}

	@Override
	public void keyTyped(KeyEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void keyPressed(KeyEvent e) {
		System.out.println("pressed");
		
	}

	@Override
	public void keyReleased(KeyEvent e) {
		// TODO Auto-generated method stub
		
	}
		
	}

