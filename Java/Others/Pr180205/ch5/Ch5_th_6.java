package ch5;

class A3
{
	public A3(int x)
	{
		System.out.print("A" + x);
	}
}

class B3 extends A3
{
	public B3()
	{
		super(20);
		System.out.print("B");
	}
	public B3(int x)
	{
		super(x+20);
		System.out.print("B" + x);
	}
		
}

public class Ch5_th_6 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		B3 b = new B3();
		System.out.println("");
		B3 b2 = new B3(30);
		

	}

}
