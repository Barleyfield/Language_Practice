package ch5;
import java.util.*;

abstract class GameObject
{
	protected int distance;
	protected int x, y;
	
	public GameObject(int startX, int startY, int distance)
	{
		this.x = startX;
		this.y = startY;
		this.distance = distance;
	}
	
	public int getX()
	{
		return x;
	}
	public int getY()
	{
		return y;
	}
	public boolean collide(GameObject p)
	{
		if(this.x == p.getX() && this.y == p.getY())
		{
			return true;
		}
		else
			return false;
	}
	
	public abstract void move(char dir, int turn);
	public abstract char getShape(GameObject p);
}

public class Ch5_Opench {
	public static class Bear extends GameObject
	{
		public Bear(int x, int y, int d)
		{
			super(x,y,d);
		}
		
		public void move(char dir, int turn)
		{
			switch(dir)
			{
			case 'w':
				if(this.x >= 1)
					this.x -= 1;
				break;
			case 'a':
				if(this.y >= 1)
					this.y -= 1;
				break;
			case 's':
				if(this.x <= 9)
					this.x += 1;
				break;
			case 'd':
				if(this.y <= 9)
					this.y += 1;
				break;
			default:
				break;
			
			}
			
		}
		
		public char getShape(GameObject p)
		{
			if(this.collide(p))
			{
				return '*';
			}
			else
				return 'B';
			
		}
		
	}
	
	public static class Fish extends GameObject
	{
		public Fish(int x, int y, int d)
		{
			super(x,y,d);
		}
		
		public void move(char dir, int turn)
		{
			Random random = new Random();
			int rand_dir_num = 0;
			char direction[] = {'w', 'a', 's', 'd'};
			char last_dir = 'x';
			if( ((turn%5 >= 3) && (turn%5 <= 4)) )
			{
				rand_dir_num = random.nextInt(5);
				last_dir = direction[rand_dir_num];
				
			}
			switch(last_dir)
			{
			case 'w':
				if(this.x >= 1)
					this.x -= 1;
				break;
			case 'a':
				if(this.y >= 1)
					this.y -= 1;
				break;
			case 's':
				if(this.x <= 9)
					this.x += 1;
				break;
			case 'd':
				if(this.y <= 9)
					this.y += 1;
				break;
			default:
				break;
			}
			
		}
		
		public char getShape(GameObject b)
		{
			if(this.collide(b))
			{
				return '*';
			}
			else
				return '@';
		
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		char input_dir = 'x';
		char field[][] = new char[10][10];
		int turn_count = 0;
		Bear b = new Bear(0,0,0);
		Fish f = new Fish(1,1,0);
		int i=0, j=0;
		
		
		while(true)
		{
			for(i=0; i<10; i++)
			{
				for(j=0; j<10; j++)
				{
					if( (b.getX() == i) && (b.getY() == j) )
					{
						field[i][j] = 'B';
					}					
					else
						field[i][j] = '-';
					
					
					
					if( (f.getX() == i) && (f.getY() == j) )
					{
						field[i][j] = '@';
					}
					else
					{
						if( field[i][j] != 'B')
						{
							field[i][j] = '-';
						}
					}
				}
			}
			
			for(i=0; i<10; i++)
			{
				for(j=0; j<10; j++)
				{
					System.out.print(field[i][j]);
					
				}
				System.out.println("");
				
			}
			System.out.print("Up(w), Left(a), Down(s), Right(d) : ");
			input_dir = s.next().charAt(0);
			b.move(input_dir, turn_count);
			f.move(input_dir, turn_count);
			System.out.println("\r");
			
			if(b.collide(f))
			{
				
				System.out.println("Bear Wins!");
				break;
			}
			
			turn_count += 1;
			
		}
		
		s.close();	
	}
	
}
	


		
		
		


	
	


