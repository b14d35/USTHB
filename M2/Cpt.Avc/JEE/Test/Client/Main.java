import javax.naming.Context;
import javax.naming.NamingException;

import multiplication.MultRemote;
import EJBClient.ContextEJB;


public class Main {
	public static void main(String[] args) throws NamingException {
		Context ctx = ContextEJB.getInitialContext();
		MultRemote fun = (MultRemote) ctx.lookup("MultBean/remote");
		fun.afficher("b14", "d35");
	}

}