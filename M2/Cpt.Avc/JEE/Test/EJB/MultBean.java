package multiplication;

import javax.ejb.Stateless;

@Stateless
public class MultBean implements MultRemote {

	public void afficher(String nom, String prenom) {
		System.out.println("Bonjour "+nom.toUpperCase()+" "+prenom+". Voici la table de multiplication:");
		for(int i=1; i<10; i++){
			String s = "";
			for(int j=1; j<10; j+=2){
				s += j+"*"+i+"="+(i*j)+".\t";
			}
			System.out.println(s);
		}
		System.out.println("--------------------------------------");
		for(int i=1; i<10; i++){
			String s = "";
			for(int j=2; j<=10; j+=2){
				s += j+"*"+i+"="+(i*j)+".\t";
			}
			System.out.println(s);
		}
	}
	
}
