package testTp1;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.rmi.NotBoundException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;


public class P2 {
	public static void main(String[] args) {
		try {
			DatagramSocket serverSocket = new DatagramSocket(8888);
			byte[] receiveData = new byte[10];
			DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
			serverSocket.receive(receivePacket);
			String data = new String(receivePacket.getData());
			InetAddress IPAddress = receivePacket.getAddress();
			int port = receivePacket.getPort();
			System.out.println("RECEIVED: "+data.trim()+" - From Address: "+IPAddress+" - Port: "+port);
			int N = Integer.parseInt(data.trim());
			int M = N*2;
			InterMysql rmiServer;
			Registry registry;
			String Adress = "localhost";
			int Port = 7777;
			
			registry = LocateRegistry.getRegistry(Adress, Port);
			System.out.println("RMI registry found on port "+Port);
			rmiServer = (InterMysql)(registry.lookup("rmiServer"));
			rmiServer.calcul(M);
		} catch (IOException | NotBoundException e) {
			e.printStackTrace();
		}
	}
}
