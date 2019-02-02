package Pr180104;

public class Ch4_4 {
	public static class Book
	{
		String title, author;
		public Book(String t)
		{
			title = t;
			author = "작자 미상";
		}
		public Book(String t, String a)
		{
			title = t;
			author = a;
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Book javabook = new Book("Java", "황기태");
		Book bible = new Book("Bible");
		System.out.println(javabook.author);
		

	}

}
