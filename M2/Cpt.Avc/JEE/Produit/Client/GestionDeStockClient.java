package produittest;

import java.util.Iterator;
import java.util.List;
import java.util.Properties;

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;

import org.apache.log4j.Level;
import org.apache.log4j.Logger;

import produit.GestionDeStock;
import produit.Produit;

public class GestionDeStockClient {
	public static void main(String[] args) throws NamingException {
		Logger.getRootLogger().setLevel(Level.OFF);
		Properties props = System.getProperties();
		props.put(Context.INITIAL_CONTEXT_FACTORY, "org.jnp.interfaces.NamingContextFactory");
		props.put(Context.URL_PKG_PREFIXES, "org.jboss.naming:org.jnp.interfaces");
		props.put(Context.PROVIDER_URL, "jnp://localhost:1099");
		Context ctx = new InitialContext(props);
		GestionDeStock stock = (GestionDeStock) ctx.lookup("GestionDeStockBean/remote");
		// Insertion plusieurs fois generates a problem
		stock.ajouter(new Produit("1401", "Tomate", 100));
		stock.ajouter(new Produit("1402", "Pomme de terre", 5680));
		stock.ajouter(new Produit("1403", "Orange", 23));
		stock.ajouter(new Produit("1404", "Carotte", 115));
		stock.ajouter(new Produit("1405", "Pomme", 48));
		stock.ajouter(new Produit("1406", "Aubergine", 69));
		List<Produit> produits = stock.afficher();
		for (Iterator iterator = produits.iterator(); iterator.hasNext();) {
			Produit produit = (Produit) iterator.next();
			System.out.println(produit);
		}
 	}
	
}
