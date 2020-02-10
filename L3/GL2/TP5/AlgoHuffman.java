import java.io.IOException;
import java.util.ArrayList;

public class AlgoHuffman{
	ArrayList<NoeudHuffman> listeCaracteres = new ArrayList<NoeudHuffman>();
	public void construireListe(String nomFichier) throws IOException{
		ScanPlus scan = new ScanPlus(nomFichier);
		char c;
		while ((c = scan.nextChar()) != 0) ajouter(c);
	}
	public void ajouter(char c){
		NoeudHuffman x = new NoeudHuffman(c);
		int s=0;
		for(NoeudHuffman t:listeCaracteres){
			if(x.getCaractere()==t.getCaractere()) {
				t.incremente();
				s=1;
				break;
			}
		}
		if(s==0) listeCaracteres.add(x);
	}
	public NoeudHuffman huffman(){
		listeCaracteres.sort(null);
		ArrayList<NoeudHuffman> copieList = (ArrayList<NoeudHuffman>)listeCaracteres.clone();
		while(copieList.size()>1){
			NoeudHuffman x = new NoeudHuffman('£');
			x.setFilsG(copieList.get(0));
			x.setFilsD(copieList.get(1));
			x.setNbOcc(copieList.get(0).getNbOcc()+copieList.get(1).getNbOcc());
			copieList.set(1, x);
			copieList.remove(0);
			copieList.sort(null);
		}
		return copieList.get(0);
	}
	public void determinerCodes(NoeudHuffman racine, StringBuffer chaine){
		String a = chaine.toString()+"0";
		String b = chaine.toString()+"1";
		if(racine.getFilsG()!=null){
			racine.getFilsG().setCode(a);
			determinerCodes(racine.getFilsG(), new StringBuffer().append(a));
		}
		if(racine.getFilsD()!=null){
			racine.getFilsD().setCode(b);
			determinerCodes(racine.getFilsD(), new StringBuffer().append(b));
		}
	}
	public void ecrire(){
		for(NoeudHuffman x:listeCaracteres) System.out.println(x);
	}
	public static void main(String[] args) throws IOException {
		// Le fichier de test est mis dans le dossier de travail et nommé t.txt
		System.out.println("Construction et tri selon la fréquence :");
		AlgoHuffman x = new AlgoHuffman();
		NoeudHuffman.optionTri=2;
		x.construireListe("t.txt");
		x.determinerCodes(x.huffman(), new StringBuffer());
		x.ecrire();
		System.out.println("Construction et tri selon la Clé :");
		AlgoHuffman y = new AlgoHuffman();
		NoeudHuffman.optionTri=1;
		y.construireListe("t.txt");
		y.determinerCodes(y.huffman(), new StringBuffer());
		y.ecrire();
	}
}
