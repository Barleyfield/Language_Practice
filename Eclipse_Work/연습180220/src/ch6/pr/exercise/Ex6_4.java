package ch6.pr.exercise;
import java.util.*;

public class Ex6_4 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		String calc = s.nextLine();
		int result = 0;
		String split;
		StringTokenizer st = new StringTokenizer(calc, "+");
		while(st.hasMoreTokens())
		{
			split = st.nextToken();
			split = split.replaceAll(" ", "");
			split = split.replaceAll("\\p{Z}",  "");
			
			result += Integer.parseInt(split);
		}
		System.out.println("Sum is " + result);
		s.close();

	}

}
