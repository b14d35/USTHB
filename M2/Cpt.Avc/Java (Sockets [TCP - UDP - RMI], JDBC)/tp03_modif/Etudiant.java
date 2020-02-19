package tp03_modif;

import java.io.Serializable;

public class Etudiant implements Serializable{
	private int mat;
	private String nom, prenom;
	public Etudiant(int mat, String nom, String prenom) {
		super();
		this.mat = mat;
		this.nom = nom;
		this.prenom = prenom;
	}
	public int getMat() {
		return mat;
	}
	public String getNom() {
		return nom;
	}
	public String getPrenom() {
		return prenom;
	}
	public String toString() {
		return "Etudiant [mat=" + mat + ", nom=" + nom + ", prenom=" + prenom + "]";
	}
	
}
