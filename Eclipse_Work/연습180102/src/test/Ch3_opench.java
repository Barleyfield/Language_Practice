package test;
import java.util.Scanner;
import java.util.Random;

public class Ch3_opench {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Random r = new Random();
		Scanner s = new Scanner(System.in);
		int com_num = r.nextInt(100);
		int answer = -1;
		int left = 0, right = 99, turn = 1;
		System.out.println("수를 결정하였습니다. 맞추어 보세요.");
		System.out.println(com_num);
		while(com_num != answer)
		{
			System.out.println(left + "-" + right);
			System.out.print(turn + ">>");
			answer = s.nextInt();
			
			if( answer < com_num)
			{
				System.out.println("더 높게!");
				left = answer;
			}
			else if (answer > com_num)
			{
				System.out.println("더 낮게!");
				right = answer;
			}
			turn++;
		}
	
		System.out.println("맞았습니다.");
		s.close();
	}

}
