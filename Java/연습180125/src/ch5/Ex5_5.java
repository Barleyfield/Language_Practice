package ch5;

abstract class Calculator
{
	public abstract int add(int a, int b);
	public abstract int subtract(int a, int b);
	public abstract double average(int[] a);
}

// 


public class Ex5_5 {
	public static class GoodCalc extends Calculator
	{
		public int add(int a, int b)
		{
			return a+b;
		}
		public int subtract(int a, int b)
		{
			return a-b;
		}
		
		public double average(int[] a)
		{
			int i=0;
			double result = 0;
			for(i=0; i<a.length; i++)
			{
				result += a[i];
			}
			return (result/(a.length));
			
		}
		
		
		
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		GoodCalc c = new GoodCalc();
		System.out.println(c.add(2,3));
		System.out.println(c.subtract(2,3));
		System.out.println(c.average(new int[] {2,3,4}));

	}

}
