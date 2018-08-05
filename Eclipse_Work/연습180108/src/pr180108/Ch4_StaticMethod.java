package pr180108;

class StaticMethod
{
	int n;
	static int m;
	void f1(int x)
	{
		n=x;
	}
	void f2(int x)
	{
		m = x;
	}
	static void s1(int x)
	{
		n = x;
	}
	static void s2(int x)
	{
		f1(3);
	}
	static void s3(int x)
	{
		m=x;
	}
	static void s4(int x)
	{
		s3(3);
	}

}

public class Ch4_StaticMethod {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
