package calcule;

import javax.ejb.Remote;

@Remote
public interface Calcule {
	int Add(int x, int y);
	int Mul(int x, int y);
	int Div(int x, int y);
}
