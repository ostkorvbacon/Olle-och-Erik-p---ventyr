import wheels.users.*;

public class Breakoutgame extends Frame 
{
	static final int BNUM1 = 14, BNUM2 = 13;
	private static brick _brick;
	private static Ball _ball;
	private static Background _background;
	private static Bat _bat;
	private static Edges _edges;
	
	public Breakoutgame()
	{
		brick _brickArr1[] = new brick[BNUM1];
		brick _brickArr2[] = new brick[BNUM2];
		brick _brickArr3[] = new brick[BNUM1];
		brick _brickArr4[] = new brick[BNUM2];


		_background = new Background();
		_edges = new Edges();
		for(int i=0; i<BNUM1; i++)
		{
			_brickArr1[i] = new brick((i*50)+1,25);
			_brickArr3[i] = new brick((i*50)+1,75);

		}
		for(int i =0; i<BNUM2; i++)
		{
			_brickArr2[i] = new brick((i*50)+26,50);
			_brickArr4[i] = new brick((i*50)+26,100);
		}
		_ball = new Ball(340, 450);
		_bat = new Bat(300, 480);
	}
	public static void main(String[] argv ) 
	{
		Breakoutgame game = new Breakoutgame();
	}

}
