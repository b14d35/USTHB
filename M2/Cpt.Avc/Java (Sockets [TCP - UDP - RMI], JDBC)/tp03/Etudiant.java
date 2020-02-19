package tp03;

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
	@Override
	public boolean equals(Object o) {
		if (o instanceof Etudiant){
			Etudiant x = (Etudiant) o;
			return x.mat == mat && x.nom.equals(nom) && x.prenom.equals(prenom);
		}
		return false;
	}
}
