import java.util.InputMismatchException;
import java.util.Random;
import java.util.Scanner;

public class Test {
	static void menu(){
		System.out.println("\t\t--------Menu Principal--------");
		System.out.println("\t\t1- Ajouter \t2- Rechercher");
		System.out.println("\t\t3- Serializer \t4- Restorer");
		System.out.println("\t\t5- Save XML \t6- Afficher");
		System.out.println("\t\t\t 0- Quitter");
		System.out.println("\t\t\t Votre Choix: \t");
	}
	public static void main(String[] args) {
		TreeIL<Integer> tree = new TreeIL<Integer>();
		Scanner sc = new Scanner(System.in);
		Random rand = new Random();
		for(int i=0;i<10;i++){
			int x = rand.nextInt(20);
			tree.insert(x);
		}
		int choix = 1;
		do{
			menu();
			try{
				choix = sc.nextInt();
			}catch(InputMismatchException e){
				System.out.println("Votre choix est erroné");
				choix = 7;
				sc.nextLine();
			}
			switch(choix){
				case 1:
					System.out.println("Entrez une valeur à ajouter:");
					try {
						if(tree.insert(sc.nextInt())){
							System.out.println("Valeur inseré avec succes");
						}else{
							System.out.println("Echec de l'insertion");
						}
					} catch (InputMismatchException e) {
						System.out.println("Valeur erronée");
						sc.nextLine();
					}
					break;
				case 2:
					System.out.println("Entrez une valeur à recherche:");
					try {
						if(tree.find(sc.nextInt())){
							System.out.println("La valeur existe");
						}else{
							System.out.println("La valeur est introuvable");
						}
					} catch (InputMismatchException e) {
						System.out.println("Valeur erronée");
						sc.nextLine();
					}
					break;
				case 3:
					if(tree.taille()>0){
						if(tree.saveSER()){
							System.out.println("Serialisation avec success");
						}else{
							System.out.println("Erreur de serialisation");
						}
					}else{
						System.out.println("Aucun élément a sérialiser");
					}
						
					break;
				case 4:
					if(tree.restore()){
						System.out.println("Restoration avec success");
					}else{
						System.out.println("Erreur de restoration");
					}
					break;
				case 5:
					if(tree.saveXML()){
						System.out.println("Ficher XML généré");
					}else{
						System.out.println("Erreur lors de la création du fichier XML");
					}
					break;
				case 6:
					System.out.println("Affichage");
					if(tree.taille() == 0){
						System.out.println("L'arbre est vide");
					}else{
						tree.display();
					}
					break;
				case 0:
					System.out.println("Programme terminé");
					break;
				default:
					break;
			}
		}while(choix != 0);
		
	}

}
