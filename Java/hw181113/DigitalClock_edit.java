package hw181113;

/*
 * 142694 윤이삭 디지털 시계
 * AM/PM 표시, 깜박임
 */

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.Calendar;

public class DigitalClock_edit {
	public static void main(String[] args) {

		JFrame frame = new JFrame();
		JPanel clock = new ClockPanel();
		frame.getContentPane().add(clock);
		frame.setTitle("디지털 시계");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.pack();
		frame.setVisible(true);
	}
}

class ClockPanel extends JPanel
{
	private JTextField timeField;
	private Timer t;
	
	public ClockPanel()
	{
		timeField = new JTextField(7);		// 크기를 7로 해야 AM,PM이 나온다.
		timeField.setEditable(true);
		timeField.setFont(new Font("sansserif", Font.PLAIN, 48));
		add(timeField);
		
		t = new Timer(1000, new ClockListener());
		t.start();
	}

	class ClockListener implements ActionListener
	{
		public void WaitTime(int delayTime)
		{
		    long saveTime = System.currentTimeMillis();
		    long currTime = 0;
		    
		    while( currTime - saveTime < delayTime)
		    {
		        currTime = System.currentTimeMillis();
		    }
		}
		
		public void actionPerformed(ActionEvent e)
		{
			Calendar time = Calendar.getInstance();
			String TimeText = "";					// 시간 텍스트 나타내는 문자열
			int hour = time.get(Calendar.HOUR_OF_DAY);
			if(hour >= 13)
			{
				hour -= 12;
				TimeText += "PM";	// 13시가 넘으면(오후면) 시간 텍스트 앞부분에 PM 추가
			}
			else
			{
				TimeText += "AM";	// 13시가 넘지 않으면(오전이면) 시간 텍스트 앞부분에 AM 추가
			}
			int min = time.get(Calendar.MINUTE);
			int sec = time.get(Calendar.SECOND);
			

			if(sec % 2 == 0)
			{
				TimeText += " " + (hour<10 ? "0"+hour : hour) + ":" + (min<10 ? "0"+min : min) + ":" + (sec<10 ? "0"+sec : sec);	
				timeField.setText(TimeText);
			}
			else
			{
				TimeText += " " + (hour<10 ? "0"+hour : hour) + " " + (min<10 ? "0"+min : min) + " " + (sec<10 ? "0"+sec : sec);	
				timeField.setText(TimeText);			
			}
			
		}
	}
}
