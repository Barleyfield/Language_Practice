package ch5;

class A4
{
	int i;
}
class B4 extends A4
{
	int j;
}
class C4 extends B4
{
	int k;
}
class D4 extends B4
{
	int k;
}

public class Ch5_th_8 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		A4 c = new C4();
		System.out.println(c instanceof D4);
		System.out.println(c instanceof A4);
		
		System.out.println(new D4() instanceof C4);
		System.out.println(new D4() instanceof A4);
		

	}

}
