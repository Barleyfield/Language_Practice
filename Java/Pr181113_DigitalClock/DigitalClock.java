package pr181113;

/*
 * 142694 윤이삭 디지털 시계
 */

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.Calendar;

public class DigitalClock {
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
		timeField = new JTextField(5);
		timeField.setEditable(true);
		timeField.setFont(new Font("sansserif", Font.PLAIN, 48));
		add(timeField);
		
		t = new Timer(1000, new ClockListener());
		t.start();
	}

	class ClockListener implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			Calendar time = Calendar.getInstance();
			int hour = time.get(Calendar.HOUR_OF_DAY);
			int min = time.get(Calendar.MINUTE);
			int sec = time.get(Calendar.SECOND);
			timeField.setText("" + (hour<10 ? "0"+hour : hour) + ":" + (min<10 ? "0"+min : min) + ":" + (sec<10 ? "0"+sec : sec));
			
		}
	}
}




