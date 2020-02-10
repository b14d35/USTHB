
public class NoeudHuffman implements Comparable<NoeudHuffman>{
	private char caractere;
	private int nbOcc;
	private NoeudHuffman filsG,filsD;
	private String code;
	public static int CARACTERE=1,NB_OCC=2;
	public static int optionTri;
	@Override
	
	public int compareTo(NoeudHuffman autre) {
		if(optionTri==CARACTERE){
			if(caractere==autre.caractere) return 0;
			else if(caractere>autre.caractere) return 1;
			else return -1;
		}
		else{
			if(nbOcc==autre.nbOcc) return 0;
			else if(nbOcc>autre.nbOcc) return 1;
			else return -1;
		}
	}
	@Override
	public String toString() {
		return ""+caractere+" | "+nbOcc+" | "+code+"";
	}
	public NoeudHuffman(char caractere) {
		this.caractere = caractere;
		nbOcc=1;
		filsD=null;
		filsG=null;
	}
	public char getCaractere() {
		return caractere;
	}
	public int getNbOcc() {
		return nbOcc;
	}
	public void setNbOcc(int nbOcc) {
		this.nbOcc = nbOcc;
	}
	public void incremente(){
		nbOcc++;
	}
	public void setFilsD(NoeudHuffman filsD) {
		this.filsD = filsD;
	}
	public void setFilsG(NoeudHuffman filsG) {
		this.filsG = filsG;
	}
	public NoeudHuffman getFilsG() {
		return filsG;
	}
	public NoeudHuffman getFilsD() {
		return filsD;
	}
	public void setCode(String code) {
		this.code = code;
	}
}
