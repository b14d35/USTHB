import java.awt.FlowLayout;
import javax.swing.JFrame;
import javax.swing.JLabel;
public class Frame extends JFrame{
	private JLabel item1;
	public Frame() {
		super("This is the title");
		setLayout(new FlowLayout());
		item1=new JLabel("This is a sentence.");
		item1.setToolTipText("This is showing up on hover");
		add(item1);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setSize(275,180);
		this.setVisible(true);
	}
}
