package Pr181015;
import java.util.*;

public class GCDandLCM {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int x=0, y=0, gcd=0, lcm=0;
		Scanner s = new Scanner(System.in);
		System.out.print("두 수를 입력하세요: ");
		x = s.nextInt();
		y = s.nextInt();
		gcd = GCD_cal(x,y);
		lcm = LCM_cal(x,y,gcd);
		System.out.println("최대공약수는 " + gcd + "입니다.");
		System.out.println("최소공배수는 " + lcm + "입니다.");
		s.close();

	}
	
	static int GCD_cal(int a, int b)
	{
		if((a%b) == 0) return b;
		else
		{
			return GCD_cal(b, a%b);
		}
	}
	
	static int LCM_cal(int a, int b, int gcd)
	{
		return (a * b) / gcd;
	}
}
