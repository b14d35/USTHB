
public class Case {
	private int num;
	public Case(int num) {
		this.num = num;
	}
	public int getNum() {
		return num;
	}
	public boolean kifKif(Case x){
		return num==x.num;
	}
	public void afficher(){
		System.out.print(" "+num);
	}
	public static boolean allLines(boolean ...x){
		for (boolean b : x) {
			if(b==false) return false;
		}
		return true;
	}
	public static boolean line(Case ...x){
		for(int i=0;i<x.length-1;i++){
			for(int j=i+1;j<x.length;j++){
				if(x[i].kifKif(x[j])) return false;
			}
		}
		return true;
	}
	public static boolean comparerAll(Case ...x){
		for(int i=0;i<x.length;i++){
			for(int j=i+1;j<x.length;j++){
				if(x[i].kifKif(x[j])) return false;
			}
		}
		return true;
	}
	 static String afficheAll(Case ...x){
		 String y="";
		for (Case case1 : x) {
			y+=case1.getNum();
		}
		return y;
	}
}
