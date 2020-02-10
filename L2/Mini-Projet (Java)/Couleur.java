
public enum Couleur {
	ROUGE, ORANGE, VERTE;
	public static Couleur setCouleur(Type x, Fleurs y){
		if(x == Type.ORDINAIRE && (y.getNbr()==0 || y.getNbr()==1)){
			return Couleur.ROUGE;
		} else if((x == Type.ORDINAIRE && (y.getNbr()==4 || y.getNbr()==3)) || ((x != Type.ORDINAIRE) && (y.getNbr()==0 || y.getNbr()==1))){
			return Couleur.ORANGE;
		} else{
			return Couleur.VERTE;
		}
	}
}
