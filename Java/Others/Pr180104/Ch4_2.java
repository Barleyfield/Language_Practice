package Pr180104;
import java.util.*;

public class Ch4_2 {
	
	public static class Rectangle
	{
		int width;
		int height;
		int getArea()
		{
			return width*height;
		}
		
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.print("너비와 높이를 입력하세요 : ");
		Scanner s = new Scanner(System.in);
		Rectangle r = new Rectangle();
		r.width = s.nextInt();
		r.height = s.nextInt();
		
		System.out.println("넓이는 : " + r.getArea());
		s.close();
		

	}

}
