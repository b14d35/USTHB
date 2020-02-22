package panier;

import java.util.Vector;

import javax.annotation.PostConstruct;
import javax.ejb.Remove;
import javax.ejb.Stateful;

@Stateful
public class PanierBean implements Panier{
	Vector articles;
	String nomClient;
	@PostConstruct
	public void initialise(){
		articles = new Vector();
		nomClient = "";
	}
	
	public void ajouterArticle(int idArticle) {
		System.out.println("Ajout d'un nouveau article");
		articles.add(new Integer(idArticle));
	}

	public void supprimerArticle(int idArticle) {
		System.out.println("Suppression d'un article");
		articles.remove(new Integer(idArticle));
	}

	public Vector listerArticles() {
		return articles;
	}

	public void setNom(String nomClient) {
		this.nomClient = nomClient;
	}

	public String getNom() {
		return nomClient;
	}
	
	@Remove
	public void remove() {
		articles = null;
	}

}
