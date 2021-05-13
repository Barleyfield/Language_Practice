package ch5;

class Point
{
	private int x,y;
	void set(int x, int y)
	{
		this.x = x;
		this.y = y;
	}
	void showPoint()
	{
		System.out.println("(" + x + "," + y + ")");
	}
}

class ColorPoint extends Point
{	
	private String color;
	void setColor(String color)
	{
		this.color = color;
	}
	void showColorPoint()
	{
		System.out.print(color);
		showPoint();
	}
	
}


public class Ex5_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Point p = new Point();
		p.set(1, 2);
		p.showPoint();
		
		ColorPoint cp = new ColorPoint();
		cp.set(3, 4);
		cp.setColor("red");
		cp.showColorPoint();

	}

}
