import wheels.users.*;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.concurrent.TimeUnit;
	

public class Background extends Frame
{
	static final int SIZE = 20000;

	private Rectangle _background;
	int score=0,hp=3,xv=(int)(Math.random()*11-5),yv=(int)Math.sqrt(5*5-xv*xv);
	
	public Background() throws InterruptedException
	{		
		_background = new Rectangle(java.awt.Color.pink);
		_background.setSize(SIZE, SIZE);
		_background.setLocation(0,0);
		
		while (xv==0 || xv==-5 || xv==5) 
		{
			xv=(int)(Math.random()*11-5);
			yv=(int)Math.sqrt(5*5-xv*xv);
		}
						
		ConversationBubble _score = new ConversationBubble("Poang:"+score+" Bollar: "+hp, ConversationBubble.TAIL_DIR_LEFT);
		_score.setLocation(100, 400);
		_score.setFrameColor(java.awt.Color.pink);
		_score.setColor(java.awt.Color.pink);
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
		bat.setWidth(1);
		while (hp>0)
		{
			if (score==60)
			{
				_score.setText("GG");
			}
			TimeUnit.MILLISECONDS.sleep(10);
			_ball.move(xv,yv);
		
			if (_ball.intersectsE()==true) 
			{ 
				hp--;
				_ball.setLocation(350, 250);
				bat.setWidth(1);
				_score.setText("Poang: "+score+" Bollar: "+hp);
				
				TimeUnit.SECONDS.sleep(1);
				xv=(int)(Math.random()*11-5);
				yv=(int)Math.sqrt(5*5-xv*xv);
				while (xv==0 || xv==-5 || xv==5) 
				{
					xv=(int)(Math.random()*11-5);
					yv=(int)Math.sqrt(5*5-xv*xv);
				}
				
			}
			
			if(_ball.intersects(b,bat)==1) 
			{
				score=score+1;
				_score.setText("Poang: "+score+" Bollar: "+hp);
			}
			if(_ball.intersects(b2,bat)==1) 
			{
				score=score+3;
				_score.setText("Poang: "+score+" Bollar: "+hp);
			}
			
			if(_ball.intersects(b3,bat)==1) 
			{
				score=score+1;
				_score.setText("Poang: "+score+" Bollar: "+hp);
			}
			_ball.intersectsbat(bat);
		}
		_score.setText("Game Over");
	}		
}