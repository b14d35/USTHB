package pcouple;

public class Couple<T> implements Comparable<T>{
	private T s1,s2;
	private static int compt=0;
	private final int num;
	public Couple(T s1, T s2) {
		super();
		this.s1 = s1;
		this.s2 = s2;
		num=++compt;
	}
	public T getS1() {
		return s1;
	}
	public void setS1(T s1) {
		this.s1 = s1;
	}
	public T getS2() {
		return s2;
	}
	public void setS2(T s2) {
		this.s2 = s2;
	}
	@Override
	public String toString() {
		return ""+num+"-"+s1+" "+s2;
	}
	@Override
	public boolean equals(Object x) {
		if(x instanceof Couple){
			Couple<T> y = (Couple<T>) x;
			return s1==y.s1 && s2==y.s2;
		}
		return false;
	}
	@Override
	public int compareTo(T x) {
		if(x instanceof Couple){
			Couple<T> y = (Couple) x;
			if(s1==s2&& y.s1==y.s2) return 0;
			if(s1<s2 || (s1==s2 && y.s1<y.s2)) return -1;
			return 1;
		}
		return 0;
	}
}
