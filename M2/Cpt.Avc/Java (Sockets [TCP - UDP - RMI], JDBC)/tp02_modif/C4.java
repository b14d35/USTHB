package tp02_modif;

import java.rmi.AlreadyBoundException;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.ArrayList;

import tp02_modif.C1_Interface;
import tp02_modif.C4_Interface;

public class C4 extends java.rmi.server.UnicastRemoteObject implements C4_Interface{
	String Address = "localhost";
	static int Port = 7777;
	ArrayList<Integer> cubiques = new ArrayList<Integer>();
	boolean amicaux = false;
	static boolean server = true, server2 = true;
	static C1_Interface rmiServerC1;
	static Registry registry2;
	
	public C4() throws RemoteException{
		System.out.println("Adress Serveur= "+Address+", Port= "+Port);
	}
	
	public void Produit(int n, int m) throws RemoteException {
		int P = n * m;
		server = false;
		while(server2);
		C4.rmiServerC1.Affichage(amicaux, cubiques);
		System.out.println("Produit: "+n+" * "+m+" = "+P);
	}
	public boolean isCubique(int x){
		int y = x, temp = 0;
		while(y>0){
			temp += Math.pow(y%10, 3);
			y /= 10;
		}
		return x == temp;
	}
	public void Cubique(int n, int m) throws RemoteException {
		cubiques.removeAll(cubiques);
		int S = n + m;
		if(S>999){
			S = 999;
		}
		for(int i=100; i<=S; i++){
			if(isCubique(i)){
				cubiques.add(i);
			}
		}
	}
	
	public void Amicaux(boolean a) throws RemoteException {
		amicaux = a;
	}
	
	public static void main(String[] args) throws RemoteException, AlreadyBoundException, NotBoundException {
		C4 s = new C4();
		System.out.println("Le serveur est pret");
		Registry registry = LocateRegistry.createRegistry(Port);
		System.out.println("Created RMI registry on port "+Port);
		registry.bind("rmiServerC4", s);
		while(C4.server);
		String Adress = "localhost";
		String Port = "8989";
		C4.registry2 = LocateRegistry.getRegistry(Adress, 8989);
		System.out.println("RMI registry found on port "+Port);
		C4.rmiServerC1 = (C1_Interface)(C4.registry2.lookup("rmiServerC1"));
		server2 = false;
	}

}
