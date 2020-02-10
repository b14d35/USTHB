package ptrip;

import pcouple.Couple;

public class Triplet<T extends Comparable<T>> extends Couple<T>{
	private T n;
	private static int cpt=0;
	public Triplet(T m, T s, T n) {
		super(m, s);
		this.n=n;
	}
	public String toString() {
		return super.toString()+" "+n;
	}
	public boolean equals(Object x) {
		if(super.equals(x)){
			if(x instanceof Triplet){
				Triplet<T> y = (Triplet<T>) x;
				if(n.equals(y.n)) return true;
				else return false;
			}
			else return false;
		} else return false;
	}
	public int compt(){
		return ++cpt;
	}
}
