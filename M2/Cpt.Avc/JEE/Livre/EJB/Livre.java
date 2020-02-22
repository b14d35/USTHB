package testing;

import java.io.Serializable;

import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.ManyToOne;
import javax.persistence.Table;

@Entity
@Table(name="MesLivres")
public class Livre implements Serializable {
	private static final long serialVersionUID = 1L;
	@Id
	private int Id;
	private String nom;
	private int annee;
	public Livre(){}
	public Livre(int id, String nom, int annee) {
		super();
		Id = id;
		this.nom = nom;
		this.annee = annee;
	}
	public String getNom() {
		return nom;
	}
	public void setNom(String nom) {
		this.nom = nom;
	}
	public int getAnnee() {
		return annee;
	}
	public void setAnnee(int annee) {
		this.annee = annee;
	}
	public int getId() {
		return Id;
	}
	@Override
	public String toString() {
		return "Livre [Id=" + Id + ", nom=" + nom + ", annee=" + annee
				 + "]";
	}
}
