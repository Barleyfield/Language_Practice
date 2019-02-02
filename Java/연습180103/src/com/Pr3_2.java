package com;
import java.util.Scanner;

public class Pr3_2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		System.out.print("정수 10개 입력 : ");
		int arr[] = new int[10];
		for(int i=0; i<10; i++)
		{
			arr[i] = s.nextInt();
		}
		
		for(int i=0; i<10; i++)
		{
			if(arr[i]%3 == 0)
				System.out.print(arr[i] + " ");
		}
		s.close();

	}

}
