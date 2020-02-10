import java.io.Serializable;
import java.util.TreeMap;

public class Annuaire implements Serializable{
	TreeMap<String,Fiche> table = new TreeMap<String,Fiche>();
	public void Ajouter(Fiche x){
		if(table.containsKey(x.getNom())==false)
			table.put(x.getNom(), x);
		else System.out.println("Cette clé existe déja");
	}
	public void Afficher(){
		for(Fiche x : table.values()) x.Afficher();
	}
	public void Rechercher(String x){
		if(table.containsKey(x)) table.get(x).Afficher();
		else System.out.println("Ficher non trouvée");
	}
}
