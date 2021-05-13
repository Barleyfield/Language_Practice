package pr180109;
import java.util.*;

class Player
{
	String name;
	Player()
	{
		name = "";
	}
	Player(String n)
	{
		name = n;
	}
}

public class Ch4_Opench {
	public static int lastIndex(String w)
	{
		return (w.length() - 1);
	}
	public static char lastChar(String w)
	{
		return (w.charAt(w.length() - 1));
	}
	public static char firstChar(String w)
	{
		return (w.charAt(0));
	}
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int i=0, player_num = 0;
		String word = "아버지";
		String nextword;
		boolean succeed = true;
		
		System.out.print("게임에 참가하는 인원은 몇 명입니까? : ");
		player_num = s.nextInt();
		Player p[] = new Player[player_num];
		for(i=0; i<player_num; i++)
		{
			p[i] = new Player();
		}
		for(i=0; i<player_num; i++)
		{
			System.out.print(String.format("%d", i+1) + "번째 참가자의 이름을 입력하세요 : ");
			p[i].name = s.next();
		}
		System.out.println("시작하는 단어는 " + word + "입니다.");
		
		while(succeed == true)
		{
			for(i=0; i<player_num; i++)
			{
				System.out.print(p[i].name + " : ");
				nextword = s.next();
				if( lastChar(word) != firstChar(nextword) )
				{
					System.out.println(p[i].name + "이 졌습니다.");
					succeed = false;	
					break;
				}
				word = nextword;
			}
					
		}
		s.close();
			

	}

}
