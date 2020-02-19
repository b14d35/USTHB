package tp02_inf02;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.rmi.NotBoundException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

import tp02_inf02.C4_Interface;

public class C3 {
	static boolean amicaux(int n, int m){
		int sN = 0, sM = 0;
		int lN = n/2 + 1, lM = m/2 +1;
		for(int i=1; i<lN; i++){
			if(n%i == 0){
				sN += i;
			}
		}
		for(int i=1; i<lM; i++){
			if(m%i == 0){
				sM += i;
			}
		}
		return sN==m && sM==n;
	}
	public static void main(String[] args) throws IOException, NotBoundException {
		C4_Interface rmiServerC4;
		Registry registry;
		String Adress = "localhost";
		String Port = "7777";
		registry = LocateRegistry.getRegistry(Adress, 7777);
		System.out.println("RMI registry found on port "+Port);
		rmiServerC4 = (C4_Interface)(registry.lookup("rmiServerC4"));
		DatagramSocket serverSocket = new DatagramSocket(8888);
		byte[] receiveData;
		DatagramPacket receivePacket;
		while(true){
			receiveData = new byte[10];
			receivePacket = new DatagramPacket(receiveData, receiveData.length);
			serverSocket.receive(receivePacket);
			int N = Integer.parseInt(new String(receivePacket.getData()).trim());
			receiveData = new byte[10];
			receivePacket = new DatagramPacket(receiveData, receiveData.length);
			serverSocket.receive(receivePacket);
			int M = Integer.parseInt(new String(receivePacket.getData()).trim());
			int Sum = N + M;
			rmiServerC4.Amicaux(C3.amicaux(N, M));
			rmiServerC4.Cubique(N, M);
			rmiServerC4.Produit(N, M);
		}
	}
}
