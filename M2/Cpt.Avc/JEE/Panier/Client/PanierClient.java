
import java.util.Enumeration;
import java.util.Properties;
import java.util.Vector;

import javax.naming.Context;
import javax.naming.InitialContext;

import org.apache.log4j.Level;
import org.apache.log4j.Logger;

import panier.*;

public class PanierClient {
	public static void main(String[] args) throws Exception{
		// Adding this Line Would remove the log4j WARNINGS
				Logger.getRootLogger().setLevel(Level.OFF);
				Properties props = System.getProperties();
				props.put(Context.INITIAL_CONTEXT_FACTORY, "org.jnp.interfaces.NamingContextFactory");
				props.put(Context.URL_PKG_PREFIXES, "org.jboss.naming:org.jnp.interfaces");
				props.put(Context.PROVIDER_URL, "jnp://localhost:1099");
				Context ctx = new InitialContext(props);
				Panier monPanier = (Panier) ctx.lookup("PanierBean/remote");
				monPanier.ajouterArticle(635);
				monPanier.ajouterArticle(543);
				System.out.println("=================================");
				Vector mesArticles = monPanier.listerArticles();
				System.out.println("Il y a "+mesArticles.size()+" article(s) dans le panier !");
				Enumeration e = mesArticles.elements();
				while(e.hasMoreElements()){
					System.out.println((Integer) e.nextElement());
				}
				monPanier.ajouterArticle(323);
				monPanier.ajouterArticle(158);
				monPanier.supprimerArticle(635);
				System.out.println("=================================");
				mesArticles = monPanier.listerArticles();
				System.out.println("Il y a "+mesArticles.size()+" article(s) dans le panier !");
				e = mesArticles.elements();
				while(e.hasMoreElements()){
					System.out.println((Integer) e.nextElement());
				}
				monPanier.remove();
	}
}
