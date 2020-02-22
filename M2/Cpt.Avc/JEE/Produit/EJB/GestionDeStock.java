package produit;

import java.util.List;

import javax.ejb.Remote;

@Remote
public interface GestionDeStock {
	public void ajouter(Produit p);
	public Produit recherche(String id);
	public List<Produit> afficher();
}
