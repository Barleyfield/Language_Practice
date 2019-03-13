package pr180108;
import java.util.*;

class Player
{
	String name;
	String word;
	Player()
	{
		name = "";
		word = "시작";
	}
	Player(String n)
	{
		name = n;
		word = "시작";
	}
	String sayWord()
	{
		return word;
	}
	void getWord(String w)
	{
		word = w;
	}
	boolean succeed(String preWord)
	{
		if (word.equals(preWord))
			return true;
		else
			return false;
	}
	int lastIndex()
	{
		return (word.length() - 1);
	}
	char lastChar()
	{
		return (word.charAt(word.length() - 1));
	}
	char firstChar()
	{
		return (word.charAt(0));
	}
}

public class Ch4_Opench {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int player_num = 0;
		int i=0;
		boolean result = true;
		String word = "아버지";
		int lastIndex = word.length() - 1;
		char lastChar = word.charAt(lastIndex);
		char firstChar = word.charAt(0);
		
	
		Scanner s = new Scanner(System.in);
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
		System.out.println("시작하는 단어는 " + word +"입니다.");
		
		while(result == true)
		{
			for(i=0; i<player_num; i++)
			{
				System.out.print(p[i].name + " : ");
				p[i].word = s.nextLine();
				if( p[i].lastChar() != firstChar)
				{
					System.out.println(p[i].name + "이 졌습니다.");
					s.close();
					System.exit(0);			
				}				
			}
			
		}	
	}

}
