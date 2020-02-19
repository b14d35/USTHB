package tp02;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.rmi.NotBoundException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

import rmi.interfaceRMI;

public class C3 {
	public static void main(String[] args) throws IOException, NotBoundException {
		DatagramSocket serverSocket = new DatagramSocket(8888);
		byte[] receiveData = new byte[10];
		while(true){
			DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
			serverSocket.receive(receivePacket);
			int N = Integer.parseInt(new String(receivePacket.getData()).trim());
			receiveData = new byte[10];
			receivePacket = new DatagramPacket(receiveData, receiveData.length);
			serverSocket.receive(receivePacket);
			int M = Integer.parseInt(new String(receivePacket.getData()).trim());
			int Sum = N + M;
			// Connect to the RMI Server
			C4_Interface rmiServer2;
			Registry registry;
			String Adress = "localhost";
			String Port = "7777";
			registry = LocateRegistry.getRegistry(Adress, 7777);
			System.out.println("RMI registry found on port "+Port);
			rmiServer2 = (C4_Interface)(registry.lookup("rmiServer2"));
			rmiServer2.Produit(N, M);
		}
	}
}
