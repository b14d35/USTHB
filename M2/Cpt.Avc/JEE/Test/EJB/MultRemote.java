package multiplication;

import javax.ejb.Remote;

@Remote
public interface MultRemote {
	void afficher(String nom, String prenom);
}
