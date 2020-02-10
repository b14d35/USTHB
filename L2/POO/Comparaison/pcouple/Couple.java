package pcouple;

public class Couple <T extends Comparable<T>> implements Comparable<Couple<T>>{
	private T m,s;
	private static int cpt=0;
	private final int num;
	public Couple(T m, T s) {
		this.m = m;
		this.s = s;
		num=compt();
	}
	public T getM() {
		return m;
	}
	public void setM(T m) {
		this.m = m;
	}
	public T getS() {
		return s;
	}
	public void setS(T s) {
		this.s = s;
	}
	public int getNum() {
		return num;
	}
	public String toString() {
		return ""+num+"-"+m+" "+s;
	}
	public boolean equals(Object x) {
		if(x==null)return false;
		else{
			if(!(x instanceof Couple))return false;
			else{
				Couple<T> y =(Couple<T>) x;
				if(s.equals(y.s) && m.equals(y.m) && num==y.num) return true;
				else return false;
			}
		}
	}
	public int compt(){
		return ++cpt;
	}
	public int compareTo(Couple<T> arg0) {
		return 0;
	}
}
