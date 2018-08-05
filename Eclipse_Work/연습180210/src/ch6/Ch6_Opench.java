package ch6;
import java.util.*;

class Histogram
{
	char alphabet[] = new char[26];
	int alpha_count[] = new int[26];
	public Histogram(String sentence)
	{
		int i=0, j=0;
		for(i=0; i<26; i++)
		{
			alphabet[i] = (char) (97+i);		// char를 붙이면 97+i가 문자로 바뀌어 a,b,c... 순으로 변환된다.
			alpha_count[i] = 0;
		}
		
		for(i=0; i<(sentence.length()); i++)
		{
			for(j=0; j<26; j++)
			{
				if(sentence.charAt(i) == alphabet[j])
				{
					alpha_count[j]++;
				}
			}
		}
	}
	public void show()
	{
		int i=0, j=0;
		System.out.println("Draw histogram.");
		for(i=0; i<26; i++)
		{
			System.out.print(alphabet[i] + " : ");
			for(j=0; j<alpha_count[i]; j++)
			{
				System.out.print("-");
			}
			System.out.println("");
		}
	}
		
}




public class Ch6_Opench {
	static String readString()		// 함수 쓸 때는 파일명 클래스 안에 쓰기! (main 안에 쓰면 오류 발생)
	{
		StringBuffer sb = new StringBuffer();
		Scanner scanner = new Scanner(System.in);
		while(true)
		{
			String line = scanner.nextLine();
			if(line.length() == 1 && line.charAt(0) == ';')
			{
				break;
			}
			sb.append(line);
		}
		return sb.toString();
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("Enter String : ");
		String result = readString();
		Histogram his = new Histogram(result);
		his.show();

	}

}
