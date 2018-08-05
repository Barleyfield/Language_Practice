package ch8;
import java.awt.*;
import javax.swing.*;

public class Ch8_1 extends JFrame{
	Ch8_1()
	{
		setTitle("300x300 스윙 프레임 만들기");
		setSize(300,300);
		setVisible(true);
		Container contentPane = getContentPane();
		JButton b = new JButton("버튼");
		b.setBackground(Color.ORANGE);
		contentPane.add(b);
		contentPane.add(new JLabel("안녕하세요"));
	}
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Ch8_1 frame = new Ch8_1();
		

	}

}

