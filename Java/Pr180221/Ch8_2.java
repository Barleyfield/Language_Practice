package ch8;
import java.awt.*;
import javax.swing.*;


public class Ch8_2 extends JFrame {
	Ch8_2()
	{
		setTitle("ContentPane°ú JFrame ¿¹Á¦");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container contentPane = getContentPane();
		contentPane.setBackground(Color.BLACK);
		contentPane.setLayout(new FlowLayout());
		
		contentPane.add(new JButton("OK"));
		contentPane.add(new JButton("Cancel"));
		contentPane.add(new JButton("Ignore"));
		contentPane.add(new JButton("Hello"));
		
		setSize(300, 150);
		setVisible(true);
		 
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Ch8_2();

	}

}
