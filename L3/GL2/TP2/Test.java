
public class Test {
	public static void main(String[] args) {
		Eleve x = new Eleve("b14d35");
		System.out.println(x);
		x.ajouterNote(12);
		x.ajouterNote(6);
		x.ajouterNote(12);
		x.ajouterNote(15);
		System.out.println(x);
		Eleve y = new Eleve("Samy");
		System.out.println(y);
		y.ajouterNote(12);
		y.ajouterNote(8);
		y.ajouterNote(11);
		y.ajouterNote(14);
		System.out.println(y);
		System.out.println(x.compareTo(y));
	}
}
