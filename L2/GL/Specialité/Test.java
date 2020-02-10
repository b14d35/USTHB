import java.util.Scanner;

public class Test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner Scan = new Scanner(System.in);
		System.out.println("Entrer une filière : ");
		String x = Scan.next();
		SpécialitéM.afficheResponsable(x);
		System.out.println("Entrer une moyenne :");
		Double y = Scan.nextDouble();
		SpécialitéM.choixPossible(y);
		System.out.println("\nAffichage des moyennes :");
		SpécialitéM.afficheMoyenne();
	}

}
