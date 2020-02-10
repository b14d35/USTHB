package etudiant;

public class Fucntion {
	public float moyenne(float notes[],int coeff[]){
		float moy=0;
		int somme=0;
		for(int i=0;i<notes.length;i++){
			moy+=notes[i]*coeff[i];
			somme+=coeff[i];
		}
		moy/=somme;
		return moy;
	}
	public static void main(String[] args) {
		
	}
}
