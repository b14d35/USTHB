import java.util.ArrayList;

public class Masculin extends Personne{
	public Masculin(String nom, String prénom, String adresse, String lieu, Date dn, Féminin mère, Masculin père,
			ArrayList<Personne> kids) {
		super(nom, prénom, adresse, lieu, dn, mère, père, kids);
		// TODO Auto-generated constructor stub
	}
	private Féminin épouse[] = new Féminin[4];
	public void setNom(String nom) {
		this.nom = nom;
	}
	public String getNom() {
		return nom;
	}
	public Contrat marier(Féminin x, Masculin a, Masculin t1, Masculin t2){
		if(x!=null){
			if(this.age()>17 && x.age()>17){
				if(this.situationFamiliale().equals("Célébataire") && x.situationFamiliale().equals("Célébataire")){
					x.setÉpoux(this);
					for(int y=0;y<4;y++){
						if(épouse[y]==null){
							if(a!=null && t1!=null && t2!=null){
								épouse[y]=x;
								return new Contrat(a,t1,t2,new Date(14,5,2018));
							}
						}
					}
				}
			}
		}
		return null;
	}
	public Féminin[] getÉpouse() {
		return épouse;
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
	public Masculin plusAgée(Masculin x){
		if (this.getDn().supérieure(x.getDn())==false) return this;
		return x;
	}
	public String situationFamiliale(){
		for(Féminin x:épouse)
			if(x==null)return "Célébataire";
		return "Marié";
	}
	@Override
	String sexe() {
		// TODO Auto-generated method stub
		return "M";
	}
}
