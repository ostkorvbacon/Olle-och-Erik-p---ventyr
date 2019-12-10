import javax.swing.JFrame;

public class Window extends JFrame
{		
	private ControlPanel _cpan;

	public Window(String title)
	{
		super(title);
		this.setSize(800, 800);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		_cpan = new ControlPanel();
		this.add(_cpan);
		this.setVisible(true);
	}
}