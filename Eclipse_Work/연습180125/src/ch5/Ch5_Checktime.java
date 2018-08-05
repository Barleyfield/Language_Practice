package ch5;

class SuperObject
{
	public void paint()
	{
		draw();
	}
	public void draw()
	{
		draw();
		System.out.println("Super Object");
	}
	
}

class SubObject extends SuperObject
{
	public void paint()
	{
		super.draw();
	}
	public void draw()
	{
		System.out.println("Sub Object");
	}
}

public class Ch5_Checktime {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		SuperObject b = new SubObject();
		b.paint();

	}

}
