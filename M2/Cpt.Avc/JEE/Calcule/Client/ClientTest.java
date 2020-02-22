import javax.naming.Context;

import EJBClient.ContextEJB;
import calcule.Calcule;

public class ClientTest {
	public static void main(String[] args) throws Exception {
		Context ctx = ContextEJB.getInitialContext();
		Calcule op = (Calcule) ctx.lookup("CalculeBean/remote");
		System.out.println("La somme de x et de y >>> "+op.Add(2, 3));
		System.out.println("La multiplication de x et de y >>> "+op.Mul(2, 3));
		System.out.println("La division de x et de y >>> "+op.Div(2, 3));
	}
}
