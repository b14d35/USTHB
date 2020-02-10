
public class IsTriangle {
	Boolean estTriangle(int a, int b, int c){
		if(a+b<=c || a+c<=b || b+c<=a || a<1 || b<1 || c<1) return false;
		return true;
	}
	Boolean estTriangleEqu(int a, int b, int c){
		if (estTriangle(a,b,c) && a==b && a==c) return true;
		return false;
	}
	Boolean estTriangleIso(int a, int b, int c){
		if(estTriangle(a,b,c) && a==b && a!=c) return true;
		return false;
	}
	Boolean estTriangleQlq(int a, int b, int c){
		if(estTriangle(a,b,c) && a!=b && a!=c && b!=c) return true;
		return false;
	}
	String triangle(int a, int b, int c){
		if(a+b<=c || a+c<=b || b+c<=a || a<1 || b<1 || c<1) return "Triangle Impossible";
		else if(a==b){
			if(a==c) return "Tringle Equilatérale";
			else return "Triangle Isolé";
		}
		else{
			if(a==c) return "Tringle Isolé";
			else return "Triangle Quelconque";
		}
	}
	public static void main(String[] args) {
		
	}
}
