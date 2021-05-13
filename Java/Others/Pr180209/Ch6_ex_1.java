package ch6;

public class Ch6_ex_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		String java = "Java";
		String cpp = "C++";
		int res = java.compareTo(cpp);
		if(res == 0)
		{
			System.out.println("the same");
		}
		else if(res < 0)
		{
			System.out.println(java + " < " + cpp);
		}
		else
			System.out.println(java + " > " + cpp + " " + res);
		
		String a = "    xyz\t";
		System.out.println(a);
		
		String b = a.trim();
		System.out.println(b);
		
		
	}

}
