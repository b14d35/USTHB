package testing;

import java.util.List;

import javax.ejb.Stateless;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;

@Stateless
public class MyBean implements MyBeanRemote {
	@PersistenceContext(unitName="Biblio")
	EntityManager em;

	@Override
	public void ajoutLivre(Livre x) {
		Livre b = rechercheLivre(x.getId());
		if(b == null){
			em.persist(x);
		}
	}

	@Override
	public Livre rechercheLivre(int id) {
		return em.find(Livre.class, id);
	}

	@Override
	public List<Livre> afficherLivre() {
		String query = "FROM Livre";
		return em.createQuery(query).getResultList();
	}

}
