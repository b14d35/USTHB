package tp02;

import java.rmi.AlreadyBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class C4 extends java.rmi.server.UnicastRemoteObject implements C4_Interface{
	String Address = "localhost";
	static int Port = 7777;
	
	public C4() throws RemoteException{
		System.out.println("Adress Serveur= "+Address+", Port= "+Port);
	}
	
	public void Produit(int n, int m) throws RemoteException {
		int P = n * m;
		System.out.println("Produit: "+n+" * "+m+" = "+P);
	}
	
	public static void main(String[] args) throws RemoteException, AlreadyBoundException {
		C4 s = new C4();
		System.out.println("Le serveur est pret");
		Registry registry = LocateRegistry.createRegistry(Port);
		System.out.println("Created RMI registry on port "+Port);
		registry.bind("rmiServer2", s);
	}
}
