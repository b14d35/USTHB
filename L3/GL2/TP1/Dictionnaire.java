
public class Dictionnaire extends Volume{
	private String theme;

	public Dictionnaire(String titre, Bibliotheque bib, String auteur, String theme) {
		super(titre, bib, auteur);
		this.theme = theme;
	}
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return super.toString()+" "+theme;
	}
	public String getTheme() {
		return theme;
	}
	public void setTheme(String theme) {
		this.theme = theme;
	}
}
