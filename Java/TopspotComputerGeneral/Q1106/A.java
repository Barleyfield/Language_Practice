package Q1106;


public class A {
    int a = 10;
    public A() {
        System.out.print("가");
    }
    public A(int x) {
        System.out.print("나");
    }
    public static void main(String[] a) {
        B b1 = new B();
        A b2 = new B(1);
        System.out.print(b1.a + b2.a);
    }

}
