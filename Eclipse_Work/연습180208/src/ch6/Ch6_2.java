package ch6;

class Point2
{
	int x,y;
	public Point2(int x, int y)
	{
		this.x = x;
		this.y = y;
	}
	public String toString()
	{
		return "Point(" + x + "," + y + ")";
	}
	
}

public class Ch6_2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Point2 a = new Point2(2,3);
		Point2 b = new Point2(2,3);
		Point2 c = a;
		System.out.println(a.toString());
		System.out.println(a);
		if(a == b)
		{
			System.out.println("a==b");
		}
		if(a == c)
		{
			System.out.println("a==c");
		}

	}

}
