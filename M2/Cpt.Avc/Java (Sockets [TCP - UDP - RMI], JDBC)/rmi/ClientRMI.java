package rmi;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class ClientRMI {
	public static void main(String[] args) {
		interfaceRMI rmiServer;
		Registry registry;
		String Adress = "localhost";
		int Port = 7777;
		String text = "Hello from client";
		System.out.println("Sending from clinet>>> "+text+" to "+Adress+":"+Port);
		try {
			registry = LocateRegistry.getRegistry(Adress, Port);
			System.out.println("RMI registry found on port "+Port);
			rmiServer = (interfaceRMI)(registry.lookup("rmiServer"));
			rmiServer.receiveMessage(text);
			int x = rmiServer.calcul(10, 15);
		} catch (Exception e) {
			System.out.println(e.toString());
		}
	}
}
