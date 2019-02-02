package ch8;
import java.awt.*;
import javax.swing.*;

public class Ch8_6 extends JFrame {
	Ch8_6()
	{
		setTitle("배치관리자 없이 절대 위치에 배치하는 예제");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container contentPane = getContentPane();
		
		contentPane.setLayout(null);
		
		// JLabel 컴포넌트를 생성하고 직접 위치와 크기 지정
		JLabel la = new JLabel("Hello, Press Buttons!");
		la.setLocation(130, 50);
		la.setSize(200, 20);
		contentPane.add(la);
		
		// 9개의 버튼 컴포넌트를 생성하고 동일한 크기로 설정
		// 위치는 서로 겹치게
		for(int i=1; i<=9; i++)
		{
			JButton b = new JButton(Integer.toString(i));
			b.setLocation(i*15, i*15);
			b.setSize(50,20);
			contentPane.add(b);
		}
		
		setSize(300, 200);
		setVisible(true);
	}


	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Ch8_6();
		
		
		

	}

}
