package Test2;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Produit {
	private int code, qte;
	private String nom;
	private Date fab;
	@Override
	public String toString() {
		DateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");
		return "Produit [code=" + code + ", qte=" + qte + ", nom=" + nom + ", fab=" + formatter.format(fab) + "]";
	}
	public Produit(int code, int qte, String nom, Date fab) {
		this.code = code;
		this.qte = qte;
		this.nom = nom;
		this.fab = fab;
	}
	public int getQte() {
		return qte;
	}
	public String getNom() {
		return nom;
	}
	public Date getFab() {
		return fab;
	}
	public int getCode() {
		return code;
	}
}
