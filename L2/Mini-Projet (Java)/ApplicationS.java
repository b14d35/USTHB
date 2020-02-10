
import java.util.ArrayList;

public class ApplicationS {
	
	public static void main(String[] args) {
		//Déclaration du tableau
		ArrayList<VilleS> x = new ArrayList<VilleS>();
		//Ajout des villes
		x.add(new VilleS("Alger",0,0,2,0,"Ordinaire"));
		x.add(new VilleS("Oran",1,1,2,1,"Industrielle"));
		x.add(new VilleS("Adrar",2,2,2,2,"Touristique"));
		x.add(new VilleS("Annaba",3,3,2,3,"Industrielle"));
		x.add(new VilleS("Jijel",4,4,2,4,"Agricole"));
		x.add(new VilleS("Chlef",5,5,2,0,"Ordinaire"));
		x.add(new VilleS("Constantine",6,6,2,1,"Touristique"));
		x.add(new VilleS("Setif",7,7,2,2,"Ordinaire"));
		x.add(new VilleS("SoukAhras",8,8,0,3,"Agricole"));
		x.add(new VilleS("OumLabwaki",9,9,0,4,"Ordinaire"));
		//Ajout des voisins
		x.get(0).ajout(x.get(1),x.get(2));
		x.get(1).ajout(x.get(2),x.get(3));
		x.get(2).ajout(x.get(3),x.get(4));
		x.get(3).ajout(x.get(4),x.get(5));
		x.get(4).ajout(x.get(5),x.get(6));
		x.get(5).ajout(x.get(6),x.get(7));
		x.get(6).ajout(x.get(7),x.get(8));
		x.get(7).ajout(x.get(8),x.get(9));
		//Affichage des villes
		VilleS.afficheAll(x);
		//Affichage du réseau routier
		System.out.println("\n\nLe réseau routier :");
		VilleS.reseau(x);
	}

}
