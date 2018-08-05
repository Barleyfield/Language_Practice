package ch5;

class Point2
{
	private int x,y;
	Point2()
	{
		this.x = this.y = 0;
	}
	Point2(int x, int y)
	{
		this.x = x;
		this.y = y;
	}
	void showPoint()
	{
		System.out.println("(" + x + "," + y + ")" );
	}
}

class Colorpoint2 extends Point2
{
	private String color;
	Colorpoint2(int x, int y, String color)
	{
		super(x,y);
		this.color = color;
	}
	
	void showColorpoint()
	{
		System.out.print(color);
		showPoint();
	}
}

public class Ex5_2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Colorpoint2 cp = new Colorpoint2(5,6,"blue");
		cp.showColorpoint();

	}

}
