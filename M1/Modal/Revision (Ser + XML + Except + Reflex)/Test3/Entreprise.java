package Test3;

public class Entreprise {
	private String nom;
	private int code;
	private String act;
	
	public Entreprise(String nom, int code, String act) {
		super();
		this.nom = nom;
		this.code = code;
		this.act = act;
	}

	public String toString() {
		return nom + " " + code + " " + act;
	}

	public String getNom() {
		return nom;
	}

	public int getCode() {
		return code;
	}

	public String getAct() {
		return act;
	}
	
}
