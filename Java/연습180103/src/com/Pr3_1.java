package com;
import java.util.Scanner;

public class Pr3_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		System.out.print("알파벳 한 문자를 입력하세요 : ");
		char ch = s.next().charAt(0);
		char ch_origin = ch;
		char start = 'a';
		char start_origin = 'a';
		
		while(start != ch_origin)
		{
			for( ; start <= ch_origin; start++)
			{
				System.out.print(start);
			}
			System.out.println(" ");
			start_origin++;
			start = start_origin;
		}
		System.out.println(start);
		
		/*
		거꾸로 출력
		while(ch_origin != 'a')
		{
			for( ; ch >= 'a'; ch--)
			{
				System.out.print(ch);			
			}
			System.out.println(" ");
			ch_origin--;
			ch = ch_origin;
		}
		*/ 
		s.close();
	
	}

}
