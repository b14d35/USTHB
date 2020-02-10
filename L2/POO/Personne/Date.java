
public class Date {
	private int j,m,a;

	public int getJ() {
		return j;
	}

	public void setJ(int j) {
		this.j = j;
	}

	public int getM() {
		return m;
	}

	public void setM(int m) {
		this.m = m;
	}

	public int getA() {
		return a;
	}

	public void setA(int a) {
		this.a = a;
	}

	public Date(int j, int m, int a) {
		super();
		this.j = j;
		this.m = m;
		this.a = a;
	}
	public String aff(){
		return ""+j+"/"+m+"/"+a;
	}
	public boolean supérieure(Date x){
		if(a>x.a) return true;
		else if(a==x.a){
			if(m>x.m) return true;
			else if(m==x.m){
				if(j>x.j) return true;
				else return false;
			}
			else return false;
		}
		return false;
	}
}
