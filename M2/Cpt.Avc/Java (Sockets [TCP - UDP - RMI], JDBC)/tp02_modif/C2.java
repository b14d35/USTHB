package tp02_modif;

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
		Socket connection = SocketServer.accept();
		ObjectInputStream in = new ObjectInputStream(connection.getInputStream());
		ServerSocket SocketServerP1 = new ServerSocket(8901);
		Socket connectionP1 = SocketServerP1.accept();
		ObjectInputStream inP1 = new ObjectInputStream(connectionP1.getInputStream());
		Integer M, N;
		DatagramSocket clientSocket = new DatagramSocket();
		InetAddress IPAdress = InetAddress.getByName("localhost");
		DatagramPacket sendPacket = null;
		while(true){
			M = (int)inP1.readObject();
			N = (int)in.readObject();
			// Get The DataGram out once it works
			byte[] sendData = new byte[10];
			sendData = N.toString().getBytes();
			sendPacket = new DatagramPacket(sendData, sendData.length, IPAdress, 8888);
			clientSocket.send(sendPacket);
			sendData = M.toString().getBytes();
			sendPacket = new DatagramPacket(sendData, sendData.length, IPAdress, 8888);
			clientSocket.send(sendPacket);
		}
	}
}
