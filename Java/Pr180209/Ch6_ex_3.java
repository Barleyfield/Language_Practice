package ch6;
import java.util.*;

public class Ch6_ex_3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String query = "name=kitae&addr=seoul&age=21";
		StringTokenizer st = new StringTokenizer(query, "&");
		int count = st.countTokens();
		String token = st.nextToken();
		String token2 = st.nextToken();
		System.out.println(st);
		System.out.println(count);
		System.out.println(token);
		System.out.println(token2);

	}

}
