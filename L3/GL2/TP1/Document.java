
public abstract class Document {
	protected String titre;
	protected Bibliotheque bib;
	public Document(String titre, Bibliotheque bib){
		this.titre=titre;
		this.bib=bib;
	}
	@Override
	public String toString() {
		return titre;
	}
	public String getTitre() {
		return titre;
	}
	public void setTitre(String titre) {
		this.titre = titre;
	}
	
}
