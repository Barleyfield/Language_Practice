package ch6.pr.theory;
import java.util.*;


public class Pr6_8 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int i = Integer.parseInt("123123");
		System.out.println(i);
		String t1 = Boolean.toString(true);
		if(Character.isAlphabetic('c')) System.out.println("eng");
		String t2 = Integer.toBinaryString(123);
		String t3 = Integer.toHexString(50);
		System.out.println(t1 + "\n" + t2 + "\n" + t3);
		
		StringTokenizer st = new StringTokenizer("2+3+4+6","+");
		int n = st.countTokens();
		System.out.println("토큰 개수 = " + n);
		while(st.hasMoreTokens())
		{
			System.out.print(st.nextElement() + " ");
			
		}
		
		
		
		


	}
	

}
