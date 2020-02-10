
import java.util.ArrayList;

public class ApplicationD {
	
	public static void main(String[] args) {
		//Déclaration du tableau
		ArrayList<VilleD> x = new ArrayList<VilleD>();
		//Ajout des villes
		x.add(new VilleD("Alger",0,0,0,"Ordinaire"));
		x.add(new VilleD("Oran",1,1,1,"Industrielle"));
		x.add(new VilleD("Adrar",2,2,2,"Touristique"));
		x.add(new VilleD("Annaba",3,3,3,"Industrielle"));
		x.add(new VilleD("Jijel",4,4,4,"Agricole"));
		x.add(new VilleD("Chlef",5,5,0,"Ordinaire"));
		x.add(new VilleD("Constantine",6,6,1,"Touristique"));
		x.add(new VilleD("Setif",7,7,2,"Ordinaire"));
		x.add(new VilleD("SoukAhras",8,8,3,"Agricole"));
		x.add(new VilleD("OumLabwaki",9,9,4,"Ordinaire"));
		//Ajout des voisins
		x.get(0).ajout(x.get(1),x.get(2),x.get(5));
		x.get(1).ajout(x.get(2),x.get(3),x.get(4));
		x.get(2).ajout(x.get(0),x.get(1),x.get(4));
		x.get(3).ajout(x.get(2));
		x.get(4).ajout();
		x.get(5).ajout(x.get(0));
		//Affichage des villes
		VilleD.afficheAll(x);
		//Affichage du réseau routier				
		System.out.println("\n\nLe réseau routier :");
		VilleD.reseau(x);
	}
}
