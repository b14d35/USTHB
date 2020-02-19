package tp02;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class C2 {
	public static void main(String[] args) throws IOException, ClassNotFoundException {
		ServerSocket SocketServer = new ServerSocket(6666);
		Scanner sc = new Scanner(System.in);
		System.out.println("Lire M: ");
		Integer M = sc.nextInt();
		Socket connection = SocketServer.accept();
		System.out.println("Connexion de P1 accepté");
		ObjectInputStream in = new ObjectInputStream(connection.getInputStream());
		System.out.println("N est reçu de P1");
		Integer N = (int)in.readObject();
		in.close();
		connection.close();
		// Send N and M using UDP
		DatagramSocket clientSocket = new DatagramSocket();
		InetAddress IPAdress = InetAddress.getByName("localhost");
		byte[] sendData = new byte[10];
		sendData = N.toString().getBytes();
		DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAdress, 8888);
		clientSocket.send(sendPacket);
		sendData = M.toString().getBytes();
		sendPacket = new DatagramPacket(sendData, sendData.length, IPAdress, 8888);
		clientSocket.send(sendPacket);
	}
}
