package ch5;

class LCD
{
	private int size;
	public LCD(int n)
	{
		size = n;
	}
}

class ColorLCD extends LCD
{
	int colorSize;
	public ColorLCD(int colorSize, int size)
	{
		super(size);
		this.colorSize = colorSize;
	}

}
	

public class Ch5_th_5 {
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
