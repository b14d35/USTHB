package produit;

import java.util.List;

import javax.ejb.Stateless;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;

@Stateless
public class GestionDeStockBean implements GestionDeStock{
	@PersistenceContext(unitName="IntroEJB3") 
	EntityManager em;
	
	@Override
	public void ajouter(Produit p) {
		Produit pr = recherche(p.getId());
		if(pr == null){
			em.persist(p);
		}
	}

	@Override
	public Produit recherche(String id) {
		return em.find(Produit.class, id);
	}

	@Override
	public List<Produit> afficher() {
		String q = "SELECT p FROM Produit p ORDER BY p.quantiteEnStock";
		return em.createQuery(q).getResultList();
	}

}
