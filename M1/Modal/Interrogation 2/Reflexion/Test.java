package Reflexion;

public class Test {
	public static void main(String[] args) {
		C test = new C();
		Reflexion ref = new Reflexion(test);
		ref.XML();
		ref.XML2();
	}
}
