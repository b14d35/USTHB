import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.Scanner;

public class Test {
	public static void main(String[] args) throws IOException, ClassNotFoundException {
		Annuaire annuaire = new Annuaire();
		Fiche fiche = new Fiche();
		FileOutputStream fichier;
		FileInputStream fichier2;
		ObjectOutputStream ops;
		ObjectInputStream ois;
		try {
			fichier2 = new FileInputStream("Annuaire.txt");
			ois = new ObjectInputStream(fichier2);
			final Annuaire annuaire2 = (Annuaire) ois.readObject();
			annuaire = annuaire2;
			ois.close();
		} catch (final java.io.IOException e){
			e.getStackTrace();
		}
		Scanner sc = new Scanner(System.in);
		System.out.println("Donnez la commande : ");
		String lecture = sc.nextLine();
		while(lecture.compareTo(".")!=0){
			switch(lecture.charAt(0)){
			case '?':
				if(lecture.length()>1){
					annuaire.Rechercher(lecture.substring(1, lecture.length()));
				}
				break;
			case '+':
				if(lecture.length()>1){
					fiche.setNom(lecture.substring(1, lecture.length()));
					fiche.Ajout();
					annuaire.Ajouter(fiche);
				}
				
				break;
			case '!':
				annuaire.Afficher();
				break;
			}
			System.out.println("Donnez la commande : ");
			lecture = sc.nextLine();
		}
		try {
			fichier = new FileOutputStream("Annuaire.txt");
			ops = new ObjectOutputStream(fichier);
			ops.writeObject(annuaire);
			ops.flush();
			ops.close();
		} catch (final java.io.IOException e){
			e.getStackTrace();
		}
	}
}
