package com;

public class Ch4_1 {
	public static class Circle
	{
		int radius;
		String name;
		
		public double getArea()
		{
			return 3.14*radius*radius;
		}

		
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Circle pizza = new Circle();
		pizza.radius = 10;
		pizza.name = "자바피자";
		double area = pizza.getArea();
		System.out.println(pizza.name + "의 면적은 " + area);
		
		Circle donut = new Circle();
		donut.radius = 2;
		donut.name = "자바도넛";
		area = donut.getArea();
		System.out.println(donut.name + "의 면적은 " + area);
		
		

	}

}
