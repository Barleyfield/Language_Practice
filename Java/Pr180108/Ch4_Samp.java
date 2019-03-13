package pr180108;

public class Ch4_Samp {
	int id;
	public Ch4_Samp(int x)
	{
		this.id = x;
	}
	public void set(int x)
	{
		this.id = x;
	}
	public int get()
	{
		return this.id;
	}


	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Ch4_Samp ob1 = new Ch4_Samp(3);
		Ch4_Samp ob2 = new Ch4_Samp(4);
		Ch4_Samp s;
		
		s = ob2;
		ob1 = ob2;
		System.out.println("ob1.id = " + ob1.get());
		System.out.println("ob2.id = " + ob2.get());
		


	}

}
