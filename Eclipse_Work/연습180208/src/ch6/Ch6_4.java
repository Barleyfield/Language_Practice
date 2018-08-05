package ch6;

class Rect
{
	int width, height;
	public Rect(int width, int height)
	{
		this.width = width;
		this.height = height;
	}
	public boolean equals(Rect p)
	{
		if(width*height == p.width * p.height)
		{
			return true;
		}
		else
			return false;
	}
}

public class Ch6_4 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Rect a = new Rect(2,3);
		Rect b = new Rect(3,2);
		Rect c = new Rect(3,4);
		if(a.equals(b))
		{
			System.out.println("a is equal to b");
		}
		if(a.equals(c))
		{
			System.out.println("a is equal to c");
		}
		if(b.equals(c))
		{
			System.out.println("b is equal to c");
		}
	}
}
