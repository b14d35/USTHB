package tp01;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class C2 {
	public static void main(String[] args) throws IOException, ClassNotFoundException {
		ServerSocket SocketServer = new ServerSocket(6666);
		Scanner sc = new Scanner(System.in);
		System.out.println("Lire M: ");
		int M = sc.nextInt();
		Socket connection = SocketServer.accept();
		System.out.println("Connexion de P1 accepté");
		ObjectInputStream in = new ObjectInputStream(connection.getInputStream());
		System.out.println("N est reçu de P1");
		int N = (int)in.readObject();
		in.close();
		connection.close();
		Socket SocketClient = new Socket("localhost", 7777);
		System.out.println("Attente de Connexion a P3");
		ObjectOutputStream out = new ObjectOutputStream(SocketClient.getOutputStream());
		out.writeObject(N);
		System.out.println("N est envoyé a P3");
		out.writeObject(M);
		System.out.println("M est envoyé a P3");
		out.close();
		SocketClient.close();
	}
}
