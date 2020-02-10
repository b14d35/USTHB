import java.util.LinkedList;

public class Adherent {
	private String nom,prenom;
	private Bibliotheque bib;
	LinkedList<Empruntable> livres = new LinkedList<Empruntable>();
	
	public Adherent(String nom, String prenom, Bibliotheque bib) {
		super();
		this.nom = nom;
		this.prenom = prenom;
		this.bib=bib;
	}

	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return "[Adherent] Nom : "+nom+" Prenom : "+prenom;
	}

	public String getNom() {
		return nom;
	}

	public String getPrenom() {
		return prenom;
	}
	public void setPrenom(String prenom) {
		this.prenom = prenom;
	}
	public void setNom(String nom) {
		this.nom = nom;
	}
	boolean emprunter(Empruntable x){
		if(x instanceof Livre){
			Livre y=(Livre)x;
			if(livres.size()<5){
				if(y.isDisponible() && !livres.contains(x)){
					livres.add(y);
					y.setAdherent(this);
					return true;
				}
			}
		}
		return false;
	}
	boolean rendre(Empruntable x){
		if(x instanceof Livre){
			if(livres.contains(x)){
				livres.remove(x);
				((Livre) x).setAdherent(null);
				return true;
			}
		}
		return false;
	}
	public void afficherEmprunts(){
		if(!livres.isEmpty())
		System.out.println(livres);
	}
}
