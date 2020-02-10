import java.util.ArrayList;
import java.util.Collections;

public class GroupeEleves {
	private ArrayList<Eleve> listeEleves = new ArrayList<Eleve>();
	public int nombre(){
		return listeEleves.size();
	}
	public ArrayList<Eleve> getListe() {
		return listeEleves;
	}
	public void ajouterEleve(Eleve eleve){
		listeEleves.add(eleve);
	}
	public Eleve chercher(String nom){
		for(Eleve x:listeEleves) if(x.getNom().equals(nom)) return x;
		return null;
	}
	public void lister(){
		for(Eleve x:listeEleves) x.toString();
	}
	public Eleve meilleurEleves(){
		return Collections.max(listeEleves);
	}
	public void trierEleves(){
		Collections.sort(listeEleves);
	}
}
