package Reflexion;

public class C {
	// Attributes
	private String str;
	protected int nbr;
	public float flo;
	static int in;
	final String st = "fin";
	// End Attributes
	// Constructors
	public C(){
		str = "test";
		nbr = 0;
		flo = 0;
		in = 0;
	}
	public C(int x){
		str = "test1";
		nbr = x;
		flo = x;
		in = x;
	}
	public C(String x){
		str = x;
		nbr = 0;
		flo = 0;
		in = 0;
	}
	// End Constructors
	// Methods
	public void num(int x){
		System.out.println("Number: "+x);
	}
	public String name(){
		return str;
	}
	// End Methods
}
