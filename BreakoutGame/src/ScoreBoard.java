import wheels.users.*;

public class ScoreBoard 
{
	private ConversationBubble _score;
	public void ScoreBoard()
	{
		_score.setColor(java.awt.Color.black);
		_score = new ConversationBubble("Score", ConversationBubble.TAIL_DIR_LEFT);
		_score.setLocation(450, 450);

	}
}