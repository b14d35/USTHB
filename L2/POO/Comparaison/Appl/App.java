package Appl;

import pcouple.Couple;
import ptrip.Triplet;

public class App {

	public static void main(String[] args) {
		Couple<String> a=new Couple("Samuel","Jackson");
		Couple<String> b=new Couple("Tom","Lewis");
		System.out.println(a.equals(b));
		System.out.println(a.equals(a));
		System.out.println(a);
		System.out.println(b);
		System.out.println();
		Triplet c=new Triplet("John","Harsh","Miller");
		System.out.println(c);
		Triplet d=new Triplet("Broke","Lesner","WWE");
		System.out.println(d);
	}

}
