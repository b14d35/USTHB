package Appl;

import pcouple.Couple;
import ptrip.Triplet;

public class Apple {
	public static void main(String[] args) {
		Couple<String> x1,x2;
		x1= new Couple("x","y");
		x2= new Couple("y","x");
		System.out.println(x1);
		System.out.println(x2);
		System.out.println(x1.equals(x2));
		Triplet<Integer> t1,t2;
		t1 = new Triplet(1, 2, 3);
		t2 = new Triplet(1, 2, 3);
		System.out.println(t1);
		System.out.println(t2);
		System.out.println(t1.equals(t2));
	}
}
