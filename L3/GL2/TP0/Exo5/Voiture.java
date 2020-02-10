
public class Voiture{
	private String marque, nom;
	private int production, prix;
	public int getPrix() {
		return prix;
	}
	public String getMarque() {
		return marque;
	}
	@Override
	public boolean equals(Object o) {
		if(o!=null)
			if(o instanceof Voiture){
				Voiture x = (Voiture) o;
				return x.marque==this.marque && x.nom==this.nom &&
						x.production==this.production && x.prix==this.prix;
			}
		return false;
	}
}
