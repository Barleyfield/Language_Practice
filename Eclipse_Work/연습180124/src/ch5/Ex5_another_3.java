// SuperObject
package ch5;



public class Ex5_another_3 {
	static class SuperObject
	{
		protected String name;
		public void paint()
		{
			draw();
		}
		public void draw()
		{	
			System.out.println(name);
		}
	}

	public static class SubObject extends SuperObject
	{
		protected String name;
		public void draw()
		{
			name = "Sub";
			super.name = "Super";
			super.draw();
			System.out.println(name);

		}
	}
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		SuperObject b = new SubObject();
		b.paint();
		
		
		
		

	}

}
