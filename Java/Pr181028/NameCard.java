/* Embedded Software 2nd Assignment */
package Pr181028;
import java.awt.*;
import javax.swing.*;

public class NameCard extends JFrame
{
	NameCard()
	{
		setTitle("명함");
		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);			// X 누르면 닫기
		setContentPane(new MyPhoto());			// 사진 넣기
		
		Container c = getContentPane();
		c.setLayout(null);						// null로 선언 (위치 수동 조정)
		
		//JPanel text_panel = new JPanel();			// 배치 관리자 선언. 선언 후 null로 설정
		//text_panel.setLayout(null);
		JLabel name = new JLabel("이름 : ");			// 이름, 학과, 학년은 JLabel 타입으로 설정.
		JLabel major = new JLabel("학과 : ");
		JLabel grade = new JLabel("학년 : ");
		JTextField name_input = new JTextField("윤이삭", 20);		// 입력하는 곳은 JTextField 타입으로 설정.
		JTextField major_input = new JTextField("전자컴퓨터공학부", 20);
		JTextField grade_input = new JTextField("3학년", 20);
		
		c.add(name);				// Container를 이용하여 추가하기
		c.add(name_input);
		c.add(major);
		c.add(major_input);
		c.add(grade);
		c.add(grade_input);
		name.setBounds(220,70,40,30);		// setBounds를 이용하여 위치 및 크기 설정
		major.setBounds(220,110,40,30);
		grade.setBounds(220,150,40,30);
		name_input.setBounds(280,70,200,30);
		major_input.setBounds(280,110,200,30);
		grade_input.setBounds(280,150,200,30);

		setSize(700,300);						
		setVisible(true);
		
		
	}
	
	class MyPhoto extends JPanel				// 사진 넣는 공간 그리기
	{
		public void paintComponent(Graphics g)
		{
			super.paintComponent(g);
			g.setColor(Color.BLACK);
			g.drawRect(60, 50, 115, 150);		// 틀 그리기
			g.drawOval(103, 95, 30, 30);		// 머리 그리기	
			g.drawRect(93, 125, 50, 70);		// 몸통 그리기

		}
	}
	

	public static void main(String[] args) {
		NameCard myCard = new NameCard();

	}

}
