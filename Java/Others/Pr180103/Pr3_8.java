package com;
import java.util.*;

public class Pr3_8 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		System.out.println("컴퓨터와 가위 바위 보 게임을 합니다.");
		String user;
		int user_num = -1;
		String str[] = { "가위", "바위", "보" };
		int n = 0;
		
		while(true)
		{
			System.out.print("가위 바위 보! : ");
			user = s.next();
			if( user.equals("그만") )
				break;
			
			switch(user)
			{
			case "가위":
				user_num = 0;
				break;
			case "바위":
				user_num = 1;
				break;
			case "보":
				user_num = 2;
				break;	
			}
			
			n = (int)(Math.random() * 3);
			
			if(user_num != n)
			{

				if( (user_num == 2 && n == 0) || (user_num == 0 && n == 2) )
				{
					if(user_num == 2)
					{
						System.out.print("사용자 = " + user + " , 컴퓨터 = ");
						System.out.print(str[n]);
						System.out.println(" , " + " 컴퓨터가 이겼습니다.");
					}
					if(n == 2)
					{
						System.out.print("사용자 = " + user + " , 컴퓨터 = ");
						System.out.print(str[n]);
						System.out.println(" , " + " 사용자가 이겼습니다.");
					}
				}
				else
				{
					if(user_num > n)
					{
						System.out.print("사용자 = " + user + " , 컴퓨터 = ");
						System.out.print(str[n]);
						System.out.println(" , " + " 사용자가 이겼습니다.");
						
					}
					if(user_num < n)
					{
						System.out.print("사용자 = " + user + " , 컴퓨터 = ");
						System.out.print(str[n]);
						System.out.println(" , " + " 컴퓨터가 이겼습니다.");
					}
				}
				
			}
			else
			{
				System.out.print("사용자 = " + user + " , 컴퓨터 = ");
				System.out.print(str[n]);
				System.out.println(" , " + " 비겼습니다.");
			}
					
		}
		System.out.println("게임을 종료합니다.");
		s.close();
		
		
	}

}
