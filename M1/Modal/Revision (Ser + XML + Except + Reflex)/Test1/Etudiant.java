package Test1;

import java.io.Serializable;

public class Etudiant implements Serializable{
	@Override
	public String toString() {
		return "Etudiant [nom=" + nom + ", prenom=" + prenom + ", matricule=" + matricule + ", niveau=" + niveau
				+ ", specialite=" + specialite + "]";
	}

	private static final long serialVersionUID = 7624017998315484440L;
	private String nom, prenom, matricule, niveau, specialite;

	public Etudiant(String nom, String prenom, String matricule, String niveau, String specialite) {
		this.nom = nom;
		this.prenom = prenom;
		this.matricule = matricule;
		this.niveau = niveau;
		this.specialite = specialite;
	}
	
}
