package testing;

import java.io.Serializable;

public class Produit implements Serializable{
	private int id;
	private String designation, type;
	private int quantite;
	public int getId() {
		return id;
	}
	public String getDesignation() {
		return designation;
	}
	public String getType() {
		return type;
	}
	public int getQuantite() {
		return quantite;
	}
	public Produit(int id, String designation, String type, int quantite) {
		super();
		this.id = id;
		this.designation = designation;
		this.type = type;
		this.quantite = quantite;
	}
	public String toString() {
		return "Produit [id=" + id + ", designation=" + designation + ", type=" + type + ", quantite=" + quantite + "]";
	}
	
}
