//추상 클래스 상속과 구현
package ch5;

abstract class A
{
	abstract int add(int x, int y);
}

abstract class B extends A
{
	void show()
	{
		System.out.println("B");
	}
}

class C extends A
{
	int add(int x, int y)
	{
		return x+y;
	}
	void show()
	{
		System.out.println("C");
	}
}

public class Ch5_another_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		C c = new C();
		
		

	}

}
