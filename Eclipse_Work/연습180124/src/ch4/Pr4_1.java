package ch4;
class Song
{
	String name;
	Song(String s)
	{
		name = s;
	}
	String getTitle()
	{
		return name;
	}
	
}

public class Pr4_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Song mySong = new Song("Let it go");
		Song yourSong = new Song("Gangnam Style");
		System.out.println("My song is : " + mySong.getTitle());
		System.out.println("Your song is : " + yourSong.getTitle());
		

	}

}
