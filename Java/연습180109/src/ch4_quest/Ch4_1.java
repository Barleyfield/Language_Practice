package ch4_quest;
class Song
{
	String title;
	Song(String t)
	{
		this.title = t;
	}
	String getTitle()
	{
		return title;
	}
	
	
}

public class Ch4_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Song mySong = new Song("Let it go");
		Song yourSong = new Song("강남스타일");
		System.out.println("내 노래는 " + mySong.getTitle());
		System.out.println("너 노래는 " + yourSong.getTitle());
		

	}

}
