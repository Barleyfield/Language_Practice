package Pr180104;

public class Ch4_5 {
	public static class Book
	{
		String title;
		String author;
		void show()
		{
			System.out.println(title + " " + author);
		}
		public Book(String title, String author)
		{
			this.title = title;
			this.author = author;
		}
		public Book(String title)
		{
			this(title, "작자 미상");
		}
		public Book()
		{
			this("","");
			System.out.println("생성자 호출됨");
		}
		
		
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Book javabook = new Book("Java", "황기태");
		Book bible = new Book("Bible");
		Book emptybook = new Book();
		
		javabook.show();
		bible.show();
		emptybook.show();

	}

}
