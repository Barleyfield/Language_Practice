package ch4_quest;
import java.util.*;

class Rect
{
	private int width, height;
	Rect()
	{
		width = 0;
		height = 0;
	}
	public Rect(int width, int height)
	{
		this.width = width;
		this.height = height;
	}
	public int getArea()
	{
		return width*height;
	}
}


public class Ch4_3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int rect_num = 4, i=0, w=0, h=0, result = 0;
		Rect rec[] = new Rect[rect_num];
		for(i=0; i<rect_num; i++)
		{
			System.out.print(String.format("%d", i+1) + " 너비와 높이 : ");
			w = s.nextInt();
			h = s.nextInt();
			rec[i] = new Rect(w, h);
		}
		for(i=0; i<rect_num; i++)
		{
			result += rec[i].getArea();
		}
		System.out.println("사각형의 전체 합은 " + result);
		s.close();
		
		

	}

}
