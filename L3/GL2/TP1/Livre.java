
public class Livre extends Volume implements Empruntable{

	public Adherent adherent;
	public Livre(String titre, Bibliotheque bib, String Auteur) {
		super(titre, bib, Auteur);
	}

	@Override
	public boolean isDisponible() {
		// TODO Auto-generated method stub
		return adherent==null;
	}
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return super.toString();
	}
	public Adherent getAdherent() {
		return adherent;
	}
	public void setAdherent(Adherent adherent) {
		this.adherent = adherent;
	}
}
