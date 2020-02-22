package testing;

import java.util.List;

import javax.ejb.Remote;

@Remote
public interface MyBeanRemote {
	void ajoutLivre(Livre x);
	public Livre rechercheLivre(int id);
	public List<Livre> afficherLivre();
}
