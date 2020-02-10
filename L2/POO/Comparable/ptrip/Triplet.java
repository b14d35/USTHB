package ptrip;

import pcouple.Couple;

public class Triplet<T> extends Couple<T>{
	private T s3;
	public Triplet(T s1, T s2, T s3) {
		super(s1, s2);
		this.s3=s3;
	}
	@Override
	public String toString() {
		return super.toString()+" "+s3;
	}
	@Override
	public boolean equals(Object x) {
		if(super.equals(x)){
			Triplet<T> y = (Triplet<T>) x;
			return s3==y.s3;
		}
		return false;
	}
}
