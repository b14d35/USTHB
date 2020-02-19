package rmi;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;

public class ServeurRMI extends UnicastRemoteObject implements interfaceRMI{
	String Address = "localhost";
	static int Port = 7777;
	
	public ServeurRMI() throws RemoteException{
		System.out.println("Adress Serveur= "+Address+", Port= "+Port);
	}
	
	public void receiveMessage(String x) throws RemoteException {
		System.out.println("Invoked method: "+x);
	}
	
	public int calcul(int a, int b) throws RemoteException {
		int sum = a + b;
		System.out.println("Invoked method calcul: "+sum);
		return sum;
	}
	
	public static void main(String[] args) {
		try {
			ServeurRMI s = new ServeurRMI();
			System.out.println("Hello Server is ready.");
			Registry registry = LocateRegistry.createRegistry(Port);
			System.out.println("Created RMI registry on port "+Port);
			registry.bind("rmiServer", s);
		} catch (Exception e) {
			System.out.println(e.toString());
			System.exit(-1);
		}
	}
}
