import java.util.ArrayList;

public class Féminin extends Personne{
	public Féminin(String nom, String prénom, String adresse, String lieu, Date dn, Féminin mère, Masculin père,
			ArrayList<Personne> kids) {
		super(nom, prénom, adresse, lieu, dn, mère, père, kids);
		// TODO Auto-generated constructor stub
	}
	private Masculin époux;
	public void setNom(String nom) {
		this.nom = nom;
	}
	public String getNom() {
		return nom;
	}
	public void setÉpoux(Masculin époux) {
		this.époux = époux;
	}
	public Masculin getÉpoux() {
		return époux;
	}
	
	public void setPrénom(String prénom) {
		this.prénom = prénom;
	}
	public Date getDn() {
		return dn;
	}
	public void setDn(Date dn) {
		this.dn = dn;
	}
	public Féminin plusAgée(Féminin x){
		if (this.getDn().supérieure(x.getDn())==false) return this;
		return x;
	}
	public String situationFamiliale(){
		if(époux==null) return "Célébataire";
		return "Mariée";
	}
	@Override
	String sexe() {
		// TODO Auto-generated method stub
		return "F";
	}
}
