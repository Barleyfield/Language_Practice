package ch5;
import java.util.*;

abstract class Calculator
{
	protected int a,b;
	abstract protected int calc();		// 추상 메소드
	protected void input()				// 두 정수를 입력받는 메소드
	{
		Scanner scanner = new Scanner(System.in);
		System.out.print("Input 2 integers : ");
		a = scanner.nextInt();
		b = scanner.nextInt();
	}
	public void run()					// 두 정수를 입력받아 계산하고 결과를 출력하는 메소드
	{
		input();
		int res = calc();
		System.out.println("The result is : " + res);
	}
}

class Adder extends Calculator
{
	public int calc()
	{
		return a+b;
	}
}

class Subtracter extends Calculator
{
	public int calc()
	{
		return a-b;
	}

}

public class Pr5_3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Adder adder = new Adder();
		Subtracter sub = new Subtracter();
		adder.run();
		sub.run();
		

	}

}
