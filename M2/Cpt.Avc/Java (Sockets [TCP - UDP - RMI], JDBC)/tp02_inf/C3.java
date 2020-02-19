package tp02_inf;

import java.io.IOException;
import java.rmi.NotBoundException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

import shortcuts.UDPServer;
import tp02_inf.C4_Interface;

public class C3 {
	public static void main(String[] args) throws IOException, NotBoundException {
		C4_Interface rmiServer2;
		Registry registry;
		String Adress = "localhost";
		String Port = "7777";
		registry = LocateRegistry.getRegistry(Adress, 7777);
		System.out.println("RMI registry found on port "+Port);
		rmiServer2 = (C4_Interface)(registry.lookup("rmiServer2"));
		UDPServer udpServer = new UDPServer(8888);
		while(true){
			int N = udpServer.readInt();
			int M = udpServer.readInt();
			int Sum = N + M;
			rmiServer2.Produit(N, M);
		}
	}
}
