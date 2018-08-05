package ch6.pr.exercise;
import java.util.*;

public class Ex6_6 {
	public static int RSP_result(int p1, int p2)
	{
		// 가위 : 0, 바위 : 1, 보 : 2
		// 사용자 : p1, 컴퓨터 : p2
		// 사용자 승리 : 0, 컴퓨터 승리 : 1
		if((p1-p2) == 1)
			return 0;
		else if( (p1-p2) == -1)
			return 1;
		else if( (p1-p2) == 2 )
			return 1;
		else
			return 0;
	}
	
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Random r = new Random();
		Scanner s = new Scanner(System.in);
		String list[] = {"가위", "바위", "보"};
		String player[] = {"사용자", "컴퓨터"};
		int choice = 0;
		int com_choice;
		while(true)
		{
			System.out.print("가위(1), 바위(2), 보(3), 끝내기(4) : ");
			choice = s.nextInt();
			choice -= 1;
			if(choice == 3)
				break;
			
			com_choice = r.nextInt(2);
			if(choice == com_choice)
			{
				System.out.println("사용자 : " + list[choice] + ", 컴퓨터 : " + list[com_choice]);
				System.out.println("비겼습니다.");
			}
			else
			{
				System.out.println("사용자 : " + list[choice] + ", 컴퓨터 : " + list[com_choice]);
				System.out.println(player[RSP_result(choice, com_choice)] + "가 이겼습니다.");
				
			}	
			
			choice = 0;
			com_choice = 0;
			
		}
		System.out.println("종료합니다.");
		s.close();

	}

}
