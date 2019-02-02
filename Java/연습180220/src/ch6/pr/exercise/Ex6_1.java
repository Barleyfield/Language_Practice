package ch6.pr.exercise;


class MyPoint
{
	int x, y;
	public MyPoint(int a, int b)
	{
		x = a;
		y = b;
	}
	public String toString()
	{
		return "MyPoint(" + x + "," + y + ")";
	}
	
	
}

public class Ex6_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MyPoint a = new MyPoint(3,20);
		System.out.println(a);
		
		

	}

}
