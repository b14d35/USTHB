
import java.util.ArrayList;

public class VilleD {
	private String nom;
	private double supérficie;
	private long habitants;
	private Type type;
	private Fleurs fleurs;
	private Couleur couleur;
	private int nbv;
	private ArrayList<VilleD> voisins = new ArrayList<VilleD>();
	private static int compt;
	private final int num;
	//Constructeur
	public VilleD(String nom, double supérficie, long habitants, int fl, String tp) {
		this.nom = nom;
		this.supérficie = supérficie;
		this.habitants = habitants;
		this.nbv = 0;
		num = ++compt;
		fleurs = Fleurs.setFleurs(fl);
		type = Type.setType(tp);
		couleur = Couleur.setCouleur(type, fleurs);
	}
	//Setters and Getters
	public int getNum() {
		return num;
	}
	public String getNom() {
		return nom;
	}
	public double getSupérficie() {
		return supérficie;
	}
	public long getHabitants() {
		return habitants;
	}
	public int getNbv() {
		return nbv;
	}
	public void setNbv(int nbv) {
		this.nbv = nbv;
	}
	public ArrayList<VilleD> getVoisins() {
		return voisins;
	}
	public Type getType() {
		return type;
	}
	public Fleurs getFleurs() {
		return fleurs;
	}
	public Couleur getCouleur() {
		return couleur;
	}
	public void setSupérficie(double supérficie) {
		this.supérficie = supérficie;
	}
	public void setHabitants(long habitants) {
		this.habitants = habitants;
	}
	public void setFleurs(Fleurs fleurs) {
		this.fleurs = fleurs;
	}
	public void setType(Type type) {
		this.type = type;
	}
	public void setCouleur(Couleur couleur) {
		this.couleur = couleur;
	}
	public void ajout(VilleD ...x){
		for(VilleD y : x)voisins.add(y);
		setNbv(getNbv()+x.length);
	}
	//Affichage d'une ville
		//Question 3
		/*La méthode de couleur est ajoutée dans le constructeur pour
		éviter l'appel à chaque fois qu'on affiche la ville*/
	public void affiche(){
		System.out.println("["+getNum()+"-"+getNom()+" : "+getSupérficie()+" Km² : "+getHabitants()+" Habitants , "+getType().name()+" , "+getFleurs().getNbr()+" Fleurs]");
	}
	//Question 4
	public boolean voisinsVide(){
		return (getNbv()==0)?true:false;
	}
	//Question 5
	public boolean voisinsTrois(){
		return (getNbv()==3)?true:false;
	}
	//Question 6
	public boolean typeDiff(){
		int x=getNbv();
		if(x<5){
			for(int j=0;j<x-1;j++){
				for(int i=j+1;i<x;i++){
					if(getVoisins().get(i).getType()==getVoisins().get(j).getType())return false;
				}
			}
		}else return false;
		return true;
	}
	//Question 7
	public boolean plusFleurie(){
		for(VilleD i : getVoisins()){
			if(i.getFleurs().getNbr()>this.getFleurs().getNbr())return false;
		}
		return true;
	}
	//Question 8
	public boolean verifier(){
		if(this.getType()!=Type.ORDINAIRE && this.getCouleur()==Couleur.VERTE){
			for(VilleD i : getVoisins()){
				if(i.getCouleur()!=Couleur.ROUGE) return false;
			}
		}else return false;
		return true;
	}
	//Méthode ajoutée pour éviter de refaire certains traitements
	public int sonVoisin(VilleD x){
		for(int i=0;i<getNbv();i++){
			if(getVoisins().get(i).getNum()==x.getNum()) return i;
		}
		return -1;
	}
	//Question 9
	public static boolean ensembleChmein(VilleD ...ens){
		for(int i=1;i<ens.length;i++){
			if(ens[i-1].sonVoisin(ens[i])==-1)return false;
		}
		return true;
	}
	ArrayList<VilleD> test = new ArrayList<VilleD>();
	//Question 10
	public boolean chemin(VilleD x){
		if(test.contains(this)==false){
			test.add(this);
			if(this.sonVoisin(x)!=-1) {
				test.removeAll(test);
				return true;
			}
			else{
				for(VilleD y:getVoisins()){
					if(y.chemin(x)==true)
					{
						test.removeAll(test);
						return true;
					}
				}
			}
		}
		test.removeAll(test);
		return false;
	}
	//Modification
	public void modifier(double supérficie, long habitants, int fl, String tp){
		setSupérficie(supérficie);
		setHabitants(habitants);
		setFleurs(Fleurs.setFleurs(fl));
		setType(Type.setType(tp));
		setCouleur(Couleur.setCouleur(getType(), getFleurs()));
	}
	//Recherche d'une ville selon le nom
	public static int chercher(String nom, ArrayList<VilleD> x){
		for(int i=0;i<x.size();i++){
			if(x.get(i).getNom().compareToIgnoreCase(nom)==0)return i;
		}
		return -1;
	}
	//Suppression
	public static void supprimer(VilleD s, ArrayList<VilleD> x){
		int p = VilleD.chercher(s.getNom(), x);
		if(p!=-1){
			x.remove(p);
			for(VilleD t : x){
				p = t.sonVoisin(s);
				if(p!=-1){
					t.getVoisins().remove(p);
					t.setNbv(t.getNbv()-1);
				}
			}
		}
	}
	//Question 12
	private static ArrayList<VilleD> temp = new ArrayList<VilleD>();
	private static ArrayList<VilleD> passe = new ArrayList<VilleD>();
	public static void reseau(ArrayList<VilleD> x){
		for(VilleD y : x){
			temp.add(y);
			if(passe.contains(y)||y.voisinsVide()){
				System.out.print("[ ");
				for(VilleD z : temp){
					System.out.print(" "+z.getNom()+" ");
				}
				System.out.print(" ]\n");
				if(!passe.contains(y))passe.add(y);
			}
			else{
				passe.add(y);
				reseau(y.getVoisins());
			}
			temp.remove(temp.size()-1);
		}
	}
	//Question 13
	public static void afficheAll(ArrayList<VilleD> x){
		ArrayList<VilleD> r = new ArrayList<VilleD>();
		ArrayList<VilleD> o = new ArrayList<VilleD>();
		ArrayList<VilleD> v = new ArrayList<VilleD>();
		for(VilleD y : x){
			if(y.getCouleur()==Couleur.ROUGE)r.add(y);
			else if(y.getCouleur()==Couleur.ORANGE)o.add(y);
			else v.add(y);
		}
		if(r.size()!=0){
			System.out.println("Les Villes ROUGES :");
			for(VilleD y : r) y.affiche();
		}
		if(o.size()!=0){
			System.out.println("Les Villes ORANGES :");
			for(VilleD y : o) y.affiche();
		}
		if(v.size()!=0){
			System.out.println("Les Villes VERTES :");
			for(VilleD y : v) y.affiche();
		}
	}
}
