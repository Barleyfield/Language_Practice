package test;
import java.util.Scanner;
import java.util.InputMismatchException;

public class Ch3_14 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		System.out.print("3개의 정수를 입력하시오 : ");
		int sum = 0, n = 0;
		for(int i=0; i<3; i++)
		{
			System.out.print(i+">>");
			try
			{
				n = s.nextInt();
			}
			catch(InputMismatchException e)
			{
				System.out.println("정수가 아닙니다. 다시 입력하세요.");
				s.next();
				i--;
				continue;
			}
			sum += n;
		}
		
		System.out.println("합은 : " + sum);
		s.close();

	}

}
