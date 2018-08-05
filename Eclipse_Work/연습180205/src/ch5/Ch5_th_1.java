package ch5;

class A
{
	private int a,b;
	public void set(int a, int b)
	{
		this.a = a;
		this.b = b;
	}
}

class B extends A
{
	protected int c,d;
}

class C extends B
{
	public int e,f;
}

public class Ch5_th_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
