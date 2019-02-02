package ch5;

class Circle
{
	private int radius;
	public Circle(int radius)
	{
		this.radius = radius;
	}
	public int getRadius()
	{
		return radius;
	}
	
}

class NamedCircle extends Circle
{
	String name;
	public NamedCircle(int r, String n)
	{
		 super(r);
		 this.name = n;
	}
	public void show()
	{
		System.out.println(name + ", ¹ÝÁö¸§ = " + this.getRadius());
	}
}

public class Pr5_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		NamedCircle w = new NamedCircle(5, "Waffle");
		w.show();

	}

}
