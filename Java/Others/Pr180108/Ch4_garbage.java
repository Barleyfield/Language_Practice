package pr180108;
class Person
{
	String name;
	Person(String n)
	{
		name = n;
	}
	void getName()
	{
		System.out.println(name);
	}
}

public class Ch4_garbage {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Person a = new Person("¿Ã∏˘∑Ê");
		Person b = new Person("º∫√·«‚");
		b = a;
		
		a.getName();
		b.getName();
		System.gc();
		

	}

}
