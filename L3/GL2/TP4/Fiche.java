import java.io.Serializable;
import java.util.Scanner;

public class Fiche implements Serializable{
	private String nom,num,adresse;
	public Fiche() {
		
	}
	public Fiche(String nom, String num, String adresse) {
		this.nom = nom;
		this.num = num;
		this.adresse = adresse;
	}
	public String getNom() {
		return nom;
	}
	public void setNom(String nom) {
		this.nom = nom;
	}
	public void Ajout(){
		Scanner sc = new Scanner(System.in);
		System.out.println("Donnez le num");
		this.num=sc.nextLine();
		System.out.println("Donnez l'adresse");
		this.adresse=sc.nextLine();
	}
	public void Afficher(){
		System.out.println("["+nom+" "+num+" "+adresse+"]");
	}
}
