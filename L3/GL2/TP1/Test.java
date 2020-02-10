import java.sql.Date;
import java.util.LinkedList;

public class Test {
	public static void main(String[] args) {
		Bibliotheque B = new Bibliotheque();
		Adherent a1 = new Adherent("Mamou", "Merzouk", B);
		Adherent a2 = new Adherent("Moudir", "Hayet", B);
		Adherent a3 = new Adherent("Mecharek", "Moh", B);
		B.addAdherant(a1);
		B.addAdherant(a2);
		B.addAdherant(a3);
		Livre l1 = new Livre("Loving What Is", B,  "Katie Byron");
		Livre l2 = new Livre("Grow Rich", B, "Napolean");
		B.addDocument(l1);
		B.addDocument(l2);
		B.addDocument(new Journal("Le Matin", B, new Date(26, 10, 2016)));
		B.addDocument(new Dictionnaire("Larousse", B, "Benjamin", "History"));
		B.addDocument(new BD("Naruto", B, "Migaso", "Hashiti"));
		a1.emprunter(l1);
		a2.emprunter(l2);
		a3.emprunter(l1);
		B.afficherFonds();
		LinkedList<Document> rech = B.rechercheeTitre("ar");
		System.out.println(rech);
	}
}
