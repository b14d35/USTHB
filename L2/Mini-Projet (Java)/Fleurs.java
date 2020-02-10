
public enum Fleurs {
	TRESFLEURIE(4),BIENFLEURIE(3),ASSEZFLEURIE(2),PEUFLEURIE(1),PASFLEURIE(0);
	private int nbr;
	private Fleurs(int nbr){
		this.nbr=nbr;
	}
	public int getNbr() {
		return nbr;
	}
	public static Fleurs setFleurs(int x){
		for(Fleurs y : Fleurs.values()){
			if(y.getNbr()==x) return y;
		}
		return null;
	}
}
