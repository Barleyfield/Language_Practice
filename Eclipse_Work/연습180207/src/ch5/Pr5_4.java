package ch5;

class Point
{
	private int x,y;
	public Point(int x, int y)
	{
		this.x = x;
		this.y = y;
	}
	public int getX()
	{
		return x;
	}
	public int getY()
	{
		return y;
	}
	protected void move(int x, int y)
	{
		this.x = x;
		this.y = y;
	}
}

class ColorPoint extends Point
{
	String color;
	public ColorPoint(int x2, int y2, String s)
	{
		super(x2, y2);
		this.color = s;
	}
	public void setPoint(int x, int y)
	{
		this.move(x, y);
	}
	public void setColor(String s)
	{
		this.color = s;
	}
	public void show()
	{
		System.out.print(this.color + "»öÀ¸·Î ");
		System.out.println("(" + this.getX() + ", " + this.getY() + ")");
	}
		
	
}


public class Pr5_4 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ColorPoint cp = new ColorPoint(5,5,"YELLOW");
		cp.setPoint(10, 20);
		cp.setColor("GREEN");
		cp.show();

	}

}
