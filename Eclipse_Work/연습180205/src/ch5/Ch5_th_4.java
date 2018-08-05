package ch5;

class A2
{
	private int x, y;
	protected void setX(int x)
	{
		this.x=x;
	}
}

class B2 extends A2
{
	private int w;
	protected void setXY(int a, int b, int c)
	{
		setX(a+b);
		y=b;
		w=c;
	}
	
}

public class Ch5_th_4 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
