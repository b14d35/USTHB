package tp03;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

public class P1 {
	
	static void Menu(){
		System.out.println("Donnez votre choix:");
		System.out.println("\t1. Ajouter un Etudiant");
		System.out.println("\t2. Supprimer un Etudaint");
		System.out.println("\t3. Rechercher un Etudiant");
		System.out.println("\t\tVotre choix: ");
	}
	
	public static void main(String[] args) throws UnknownHostException, IOException, ClassNotFoundException {
		Socket SocketClient = new Socket("localhost", 6666);
		System.out.println("Connected to localhost:6666 over TCP.");
		ObjectOutputStream out = new ObjectOutputStream(SocketClient.getOutputStream());
		ObjectInputStream in = new ObjectInputStream(SocketClient.getInputStream());
		Scanner sc = new Scanner(System.in);
		int choice;
		while(true){
			Menu();
			choice = sc.nextInt();
			out.writeObject(choice);
			switch(choice){
				case 1:
					Etudiant et;
					int mat;
					String nom, prenom;
					System.out.println("Insertion d'un etudiant.");
					System.out.println("Lire Matricule: ");
					mat = sc.nextInt();
					System.out.println("Lire Nom: ");
					nom = sc.next();
					System.out.println("Lire Prenom: ");
					prenom = sc.next();
					et = new Etudiant(mat, nom, prenom);
					out.writeObject(et);
					// Receive results
					boolean insP3 = (boolean) in.readObject();
					boolean insP4 = (boolean) in.readObject();
					if(insP3){
						System.out.println("Etudiant inseré dans P3 avec Success.");
					}else{
						System.out.println("Echec de l'insersion dans P3.");
					}
					if(insP4){
						System.out.println("Etudiant inseré dans P4 avec Success.");
					}else{
						System.out.println("Echec de l'insersion dans P4.");
					}
					break;
				case 2:
					System.out.println("Suppression d'un etudiant.");
					int matDel;
					System.out.println("Lire Matricule: ");
					matDel = sc.nextInt();
					out.writeObject(matDel);
					boolean delP3 = (boolean) in.readObject();
					boolean delP4 = (boolean) in.readObject();
					if(delP3){
						System.out.println("Etudiant supprimé de P3 avec Success.");
					}else{
						System.out.println("Echec de suppression dans P3.");
					}
					if(delP4){
						System.out.println("Etudiant supprimé de P4 avec Success.");
					}else{
						System.out.println("Echec de suppression dans P4.");
					}
					break;
				case 3:
					System.out.println("Rechercher un etudaint.");
					int matSearh;
					System.out.println("Lire Matricule: ");
					matSearh = sc.nextInt();
					out.writeObject(matSearh);
					Etudiant e3 = (Etudiant) in.readObject();
					Etudiant e4 = (Etudiant) in.readObject();
					if(e3 == null){
						System.out.println("P3: Etudiant non trouvé.");
					}else{
						System.out.println("P3: "+e3);
					}
					if(e4 == null){
						System.out.println("P4: Etudiant non trouvé.");
					}else{
						System.out.println("P4: "+e4);
					}
					if(!e3.equals(e4)){
						System.out.println("Incohérence entre BDD1 et BDD2.");
					}
					break;
				default:
					break;
			}
		}
		
	}
}
