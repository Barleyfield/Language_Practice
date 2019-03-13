package com;
import java.util.Scanner;
import java.util.*;

public class Pr3_4 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		char day[] = new char[7];
		int date = 0;
		day[0] = '일'; day[1] = '월'; day[2] = '화'; day[3] = '수'; day[4] = '목'; day[5] = '금'; day[6] = '토';

		while(true)
		{
			try
			{	
				System.out.print("정수를 입력하세요 : ");
				date = s.nextInt();
				if( date == -1)
					break;
				System.out.println(day[date%7]);
			}
			catch(InputMismatchException e)
			{
				s = new Scanner(System.in);			// Scanner의 버그로 인한 초기화 (출처 http://loveiskey.tistory.com/33)
				System.out.println("경고! 수를 입력하지 않았습니다.");
				
			}
		}
		
		System.out.println("프로그램을 종료합니다.");
		s.close();
	}

}
