import java.util.ArrayList;

public abstract class Personne {
	protected String nom, prénom, adresse, lieu;
	protected Date dn;
	protected Féminin mère;
	protected Masculin père;
	protected ArrayList<Personne> kids = new ArrayList<Personne>();
	
	public Personne(String nom, String prénom, String adresse, String lieu, Date dn, Féminin mère, Masculin père,
			ArrayList<Personne> kids) {
		super();
		this.nom = nom;
		this.prénom = prénom;
		this.adresse = adresse;
		this.lieu = lieu;
		this.dn = dn;
		this.mère = mère;
		this.père = père;
		this.kids = kids;
	}

	@Override
	public String toString() {
		return nom+" "+prénom+" "+adresse+" "+dn.aff()+" a "+lieu;
	}
	
	public void afficher(){
		System.out.println(toString());
	}
	
	abstract String sexe();
	
	public int nbEnfants(){
		return kids.size();
	}
	
	public int age(){
		Date x = new Date(14,5,2017);
		return x.getA()-dn.getA();
	}
	
	abstract String situationFamiliale();
	
	public ArrayList<Personne> enfants(){
		return kids;
	}
	
	public ArrayList<Féminin> soeurs(){
		ArrayList<Féminin> x = new ArrayList<Féminin>();
		for(Féminin y : père.getÉpouse()){
			if(y!=null){
				for(Personne z : y.enfants()){
					if(z instanceof Féminin){
						x.add((Féminin) z);
					}
				}
			}
		}
		return x;
	}
	
	public ArrayList<Personne> descendants(){
		ArrayList<Personne> temp = new ArrayList<Personne>();
		if(kids!=null)
			temp.addAll(this.enfants());
		if(kids!=null){
			for(Personne x : enfants())
				if(x!=null)temp.addAll(x.descendants());
		}
		return temp;
	}
}