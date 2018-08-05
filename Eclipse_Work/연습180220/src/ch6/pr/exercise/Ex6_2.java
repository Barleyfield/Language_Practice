package ch6.pr.exercise;
import java.util.*;

public class Ex6_2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int count = 0;
		
		
		while(true)
		{
			System.out.print("Input Text : ");
			String str = s.nextLine();
			if(str.equals("exit"))
					break;
			
			StringTokenizer st = new StringTokenizer(str, " ");
			while(st.hasMoreTokens())
			{
				count++;
				st.nextToken();
			}
			System.out.println("Number of words : " + count);
			count = 0;
		}
		System.out.println("Quit...");
		s.close();

	}

}
