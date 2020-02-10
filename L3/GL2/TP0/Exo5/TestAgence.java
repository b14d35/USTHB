import java.util.LinkedList;

public class TestAgence {
	public static void main(String[] args) {
		Agence agence = new Agence(null);
		InterCritere cri = new InterCritere();
		cri.ajouter(new CritereMarque("Renault"));
		cri.ajouter(new CriterePrix(1000));
		LinkedList<Voiture> x = agence.selectionne(new CriterePrix(1000));
		LinkedList<Voiture> y = agence.selectionne(cri);
	}
}
