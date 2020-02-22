package TestTP;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.Scanner;


public class P1 {
	public static void main(String[] args) throws RemoteException, NotBoundException {
		InterMysql rmiServer;
		Registry registry;
		String Adress = "localhost";
		int Port = 7777;
		registry = LocateRegistry.getRegistry(Adress, Port);
		System.out.println("RMI registry found on port "+Port);
		rmiServer = (InterMysql)(registry.lookup("rmiServer"));
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int S1 = N * 2;
		rmiServer.recevoir(N, S1);
	}
}
