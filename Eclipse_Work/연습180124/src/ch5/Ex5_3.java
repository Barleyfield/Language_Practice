package ch5;

class Person2 {}
class Student2 extends Person2 {}
class Researcher extends Person2 {}
class Professor extends Researcher{}


public class Ex5_3 {
	// InstanceOfEx
	static void print(Person2 p)
	{
		if(p instanceof Person2)
		{
			System.out.print("Person2 ");
		}
		if(p instanceof Student2)
		{	
			System.out.print("Student ");
		}
		if(p instanceof Researcher)
		{
			System.out.print("Researcher ");
		}
		if(p instanceof Professor)
		{
			System.out.print("Professor ");
		}
		System.out.println();
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		System.out.print("new Student() -> ");
		print(new Student2());
		System.out.print("new Researcher() -> ");
		print(new Researcher());
		System.out.print("new Professor() -> ");
		print(new Professor());
		

	}

}
