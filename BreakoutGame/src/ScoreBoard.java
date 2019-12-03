import wheels.users.*;

public class ScoreBoard 
{
	static final int SBOARDX = 450, SBOARDY = 450;
	private ConversationBubble _score;
	
	public void ScoreBoard()
	{
		_score.setColor(java.awt.Color.black);
		_score = new ConversationBubble("Score", ConversationBubble.TAIL_DIR_LEFT);
		_score.setLocation(SBOARDX, SBOARDY);

	}
}