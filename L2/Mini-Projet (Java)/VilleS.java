
import java.util.ArrayList;

public class VilleS {
	private String nom;
	private double supérficie;
	private long habitants;
	private Type type;
	private Fleurs fleurs;
	private Couleur couleur;
	private int nbv;
	private VilleS[] voisins;
	private static int compt;
	private final int num;
	//Constructeur
	public VilleS(String nom, double supérficie, long habitants, int nbv, int fl, String tp) {
		this.nom = nom;
		this.supérficie = supérficie;
		this.habitants = habitants;
		this.nbv = nbv;
		voisins = new VilleS[nbv];
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
	public VilleS[] getVoisins() {
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
	public void setNbv(int nbv) {
		this.nbv = nbv;
	}
	public void ajout(VilleS ...x){
		if(x.length==getNbv()) voisins = x;
	}
	//Affichage d'une ville
			//Question 3
			/*La méthode de couleur est ajoutée dans le constructeur pour
			éviter l'appel à chaque fois qu'on affiche la ville*/
	public void affiche(){
		System.out.println("["+getNum()+"-"+getNom()+" : "+getSupérficie()+" Km² : "+getHabitants()+" Habitants, "+getType().name()+" , "+getFleurs().getNbr()+" Fleurs]");
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
					if(getVoisins()[i].getType()==getVoisins()[j].getType())return false;
				}
			}
		}else return false;
		return true;
	}
	//Question 7
	public boolean plusFleurie(){
		for(VilleS i : getVoisins()){
			if(i.getFleurs().getNbr()>this.getFleurs().getNbr())return false;
		}
		return true;
	}
	//Question 8
	public boolean verifier(){
		if(this.getType()!=Type.ORDINAIRE && this.getCouleur()==Couleur.VERTE){
			for(int i=0;i<getNbv();i++){
				if(getVoisins()[i].getCouleur()!=Couleur.ROUGE) return false;
			}
		}else return false;
		return true;
	}
	//Méthode ajoutée pour éviter de refaire certains traitements
	public int sonVoisin(VilleS x){
		for(int i=0;i<getNbv();i++){
			if(getVoisins()[i].getNum()==x.getNum()) return i;
		}
		return -1;
	}
	//Question 9
	public static boolean ensembleChmein(VilleS ...ens){
		for(int i=1;i<ens.length;i++){
			if(ens[i-1].sonVoisin(ens[i])==-1)return false;
		}
		return true;
	}
	//QUestion 10
	public boolean chemin(VilleS x){
		if(sonVoisin(x)!=-1)return true;
		for(VilleS y : getVoisins()){
			if(y.chemin(x)==true) return true;
		}
		return false;
	}
	//Recherche d'une ville selon le nom
	public static int chercher(String nom, ArrayList<VilleS> x){
		for(int i=0;i<x.size();i++){
			if(x.get(i).getNom().compareToIgnoreCase(nom)==0)return i;
		}
		return -1;
	}
	//Modification
	public void modifier(double supérficie, long habitants, int fl, String tp){
		setSupérficie(supérficie);
		setHabitants(habitants);
		setFleurs(Fleurs.setFleurs(fl));
		setType(Type.setType(tp));
		setCouleur(Couleur.setCouleur(getType(), getFleurs()));
	}
	//Suppression
	public static void supprimer(VilleS s, ArrayList<VilleS> x){
		int p = VilleS.chercher(s.getNom(), x);
		if(p!=-1){
			x.remove(p);
			for(VilleS t : x){
				p = t.sonVoisin(s);
				if(p!=-1){
					for(int i=p+1;i<t.getNbv();i++){
						t.getVoisins()[i-1]=t.getVoisins()[i];
					}
					t.setNbv(t.getNbv()-1);
				}
			}
		}
	}
	//Question 12
	private static ArrayList<VilleS> temp = new ArrayList<VilleS>();
	private static ArrayList<VilleS> passe = new ArrayList<VilleS>();
	public static void reseau(ArrayList<VilleS> x){
		for(VilleS y : x){
			temp.add(y);
			if(passe.contains(y)||y.voisinsVide()){
				System.out.print("[ ");
				for(VilleS z : temp){
					System.out.print(" "+z.getNom()+" ");
				}
				System.out.print(" ]\n");
				if(!passe.contains(y))passe.add(y);
			}
			else{
				passe.add(y);
				ArrayList<VilleS> conv = new ArrayList<VilleS>();
				for(VilleS t : y.getVoisins()){
					conv.add(t);
				}
				reseau(conv);
			}
			temp.remove(temp.size()-1);
		}
	}
	//Question 13
	public static void afficheAll(ArrayList<VilleS> x){
		ArrayList<VilleS> r = new ArrayList<VilleS>();
		ArrayList<VilleS> o = new ArrayList<VilleS>();
		ArrayList<VilleS> v = new ArrayList<VilleS>();
		for(VilleS y : x){
			if(y.getCouleur()==Couleur.ROUGE)r.add(y);
			else if(y.getCouleur()==Couleur.ORANGE)o.add(y);
			else v.add(y);
		}
		if(r.size()!=0){
			System.out.println("Les Villes ROUGES :");
			for(VilleS y : r) y.affiche();
		}
		if(o.size()!=0){
			System.out.println("Les Villes ORANGES :");
			for(VilleS y : o) y.affiche();
		}
		if(v.size()!=0){
			System.out.println("Les Villes VERTES :");
			for(VilleS y : v) y.affiche();
		}
	}
}
