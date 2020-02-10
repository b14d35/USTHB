import java.util.LinkedList;

public class Agence {
	LinkedList<Voiture> voitures = new LinkedList<Voiture>();
	public Agence(LinkedList<Voiture> v) {
		voitures=v;
	}
	public LinkedList<Voiture> selectionne(Critere c){
		LinkedList<Voiture> temp = new LinkedList<Voiture>();
		for(Voiture v: voitures)
			if(c.correspond(v)) temp.add(v);
		return temp;
	}
}
