
public enum Type {
	AGRICOLE,TOURISTIQUE,INDUSTRIELLE,ORDINAIRE;
	public static Type setType(String x){
		for(Type y : Type.values()){
			if((y.name()).compareToIgnoreCase(x)==0) return y;
		}
		return null;
	}
}
