package shortcuts;

import java.util.ArrayList;

// Check folder ../Test/testing to see how it's used

public class Menu {
	ArrayList<String> liste;
	
	public Menu(ArrayList<String> s){
		liste = s;
	}
	
	public void show(){
		System.out.println("Donnez Votre Choix:");
		int i=1;
		for (String s : liste) {
			System.out.println("\t"+i+". "+s);
			i++;
		}
		System.out.println("\t\tVotre choix:\t");
	}
}
