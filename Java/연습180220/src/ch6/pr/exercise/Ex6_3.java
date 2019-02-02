package ch6.pr.exercise;
import java.util.*;

public class Ex6_3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Random r = new Random();
		while(true)
		{
			int val1 = r.nextInt(2) + 1;
			int val2 = r.nextInt(2) + 1;
			int val3 = r.nextInt(2) + 1;
			System.out.println(val1 + "     " + val2 + "     " + val3);
			if(val1 == val2 && val2 == val3 && val1 == val3)
				break;
			
		}
		System.out.println("Success");
		
		
		
		/*
		while(true)
		{
			double randomValue1 = Math.random();

			int val1 = (int)(randomValue * 2) + 1;
			int val2 = (int)(randomValue * 2) + 1;
			int val3 = (int)(randomValue * 2) + 1;
			System.out.println(val1 + "     " + val2 + "     " + val3);
			if(val1 == val2 && val2 == val3 && val1 == val3)
				break;
		}
		System.out.println("Success");
		*/
	}

}
