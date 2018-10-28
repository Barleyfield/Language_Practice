/* Embedded Software 2nd Assignment */
package Pr181028;
import java.util.*;

public class N_Dice {

	public static class Dice {
		private int side;	// 주사위 면의 수
		
		Dice(int n)
		{
			side = n;		// 클래스 초기화. 동시에 주사위 면의 수 설정.
		}
		public int getSide()
		{
			return side;	// 주사위 눈 반환
		}
		public void setSide(int n)
		{
			side = n;		// 주사위 눈 설정
		}
		public int getNumber()
		{
			Random rand = new Random();
			int randNum = rand.nextInt(side) + 1;	// 주사위 눈은 1부터 시작하므로 1 더하기. (범위 : 1<=x<=side)
			return randNum;
		}
		
	}

	public static void main(String[] args) {
		int side_input_1 = 0, side_input_2 = 0;
		Scanner s = new Scanner(System.in);
		System.out.print("첫 번째 주사위 눈을 입력하세요 : ");
		side_input_1 = s.nextInt();
		System.out.print("두 번째 주사위 눈을 입력하세요 : ");
		side_input_2 = s.nextInt();
		Dice d1 = new Dice(side_input_1);	// 주사위 만들기
		Dice d2 = new Dice(side_input_2);		
		int d1Num = d1.getNumber();			// 주사위 던지기
		int d2Num = d2.getNumber();
		System.out.println("첫 번째 주사위의 눈은 " + d1Num + "입니다.");
		System.out.println("두 번째 주사위의 눈은 " + d2Num + "입니다.");
		System.out.println("주사위 눈의 합 : " + (d1Num+d2Num) + "입니다.");
		s.close();
	}
}
