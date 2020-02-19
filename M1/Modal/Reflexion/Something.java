package reflex;

public class Something {
	private int int_private;
	private String string_private;
	public int int_public;
	public String string_public;
	public Something(int x, String y){
		int_private = x;
		int_public = x;
		string_private = y;
		string_public = y;
	}
	public Something(int x){
		int_private = x;
		int_public = x;
		string_public = "";
		string_private = "";
	}
	public Something(String y){
		string_private = y;
		string_public = y;
		int_private = 0;
		int_public = 0;
	}
	public int somme(){
		return int_private + int_public;
	}
	public String concat(){
		return string_private+" "+string_public;
	}
	public int test(int x, String y, Reflex zzz){
		return 0;
	}
}
