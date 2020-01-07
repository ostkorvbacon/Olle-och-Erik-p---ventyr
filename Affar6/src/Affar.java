import javax.swing.JFrame;
// Skapar förnstret som ControlPanel placeras i.
public class Affar extends JFrame
{
		
		private ControlPanel _cpan;

		public Affar(String title)
		{
			super(title);
			this.setSize(800, 800);
			this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			_cpan = new ControlPanel();
			this.add(_cpan);
			this.setVisible(true);
		}
	
		public static void main(String[] args) 
		{
			new Affar("Affär");
		}
}