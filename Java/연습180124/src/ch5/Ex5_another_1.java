package ch5;

class A
{
	
	public A()
	{
		System.out.println("생성자A");
	}
	
	public A(int x)
	{
		System.out.println("매개변수생성자A "+x);
	}
}

class B extends A
{
	public B()
	{
		System.out.println("생성자B");
	}
	public B(int x)
	{
		super(x);
		System.out.println("매개변수생성자B " + x);
	}
}
	

public class Ex5_another_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		B b;
		b = new B(5);
		

	}

}
