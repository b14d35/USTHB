import java.util.Iterator;
import java.util.List;

import javax.naming.Context;
import javax.naming.NamingException;

import testing.Livre;
import testing.MyBeanRemote;
import EJBClient.ContextEJB;


public class Main {
	public static void main(String[] args) throws NamingException {
		Context ctx = ContextEJB.getInitialContext();
		MyBeanRemote bib = (MyBeanRemote) ctx.lookup("MyBean/remote");
		bib.ajoutLivre(new Livre(1, "Cho", 2018));
		bib.ajoutLivre(new Livre(2, "Cho", 2018));
		bib.ajoutLivre(new Livre(3, "Chii", 2019));
		bib.ajoutLivre(new Livre(7, "Chii", 2009));
		System.out.println(bib.rechercheLivre(3));
		List<Livre> MesLivres = bib.afficherLivre();
		for (Iterator iterator = MesLivres.iterator(); iterator.hasNext();) {
			Livre livre = (Livre) iterator.next();
			System.out.println(livre);
		}
	}

}