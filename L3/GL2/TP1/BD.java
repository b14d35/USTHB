
public class BD extends Volume{
	private String dessinateur;

	public BD(String titre,Bibliotheque bib, String auteur, String dessinateur) {
		super(titre, bib, auteur);
		this.dessinateur = dessinateur;
	}
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return super.toString()+" "+dessinateur;
	}
	public String getDessinateur() {
		return dessinateur;
	}
	public void setDessinateur(String dessinateur) {
		this.dessinateur = dessinateur;
	}
}
