import java.util.ArrayList;

public class Eleve implements Comparable<Eleve>{
	private String nom;
	private ArrayList<Integer> listeNotes = new ArrayList<Integer>();
	private double moyenne=0;
	public Eleve(String nom) {
		this.nom=nom;
	}
	public double getMoyenne() {
		return moyenne;
	}
	public String getNom() {
		return nom;
	}
	public ArrayList<Integer> getListeNotes() {
		return listeNotes;
	}
	public void ajouterNote(int note){
		if(note<0) listeNotes.add(0);
		else if(note>20) listeNotes.add(20);
		else listeNotes.add(note);
		moyenne=(moyenne*(listeNotes.size()-1)+note)/listeNotes.size();
	}
	@Override
	public String toString() {
		return nom+"("+moyenne+")";
	}
	public int compareTo(Eleve autreEleve) {
		if(this.getMoyenne()<autreEleve.getMoyenne()) return -1;
		else if(this.getMoyenne()>autreEleve.getMoyenne()) return 1;
		return 0;
	}
}
