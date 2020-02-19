package reflex;

public class Test {
	
	public static void main(String[] args) {
		Something x = new Something(5);
		Reflex temp = new Reflex(x);
		temp.show();
	}

}
