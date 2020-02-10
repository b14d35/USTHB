
public class Eleve {
	private String nom;
	private int niveau;
	public static int nbEleve=0;
	private final int compt;
	
	Eleve(String n, int niv){
		super();
		nom=n;
		niveau=niv;
		compt=++nbEleve;   // NOmbre d'élèves crées
	}
	Eleve(){this("???",0);}  //Initialise le nom de l'élève à ??? et son niveau à 0
	String eleve(int niv){
		niveau=niv;
		return nom;
	}
	public String getNom(){return nom;}
	public void setNiveau(int niv){niveau=niv;}
	public String toString(){
		return "Eleve "+compt+" "+nom+" niveau "+niveau;
	}
}
