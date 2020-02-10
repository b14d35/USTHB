
public class Volume extends Document{
	private String Auteur;

	public Volume(String titre,Bibliotheque bib,String auteur) {
		super(titre,bib);
		Auteur = auteur;
	}
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return super.toString()+" "+Auteur;
	}
	public String getAuteur() {
		return Auteur;
	}
}
