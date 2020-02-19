package tp01_2;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class C1 {
	public static void main(String[] args) throws IOException, ClassNotFoundException {
		Scanner sc = new Scanner(System.in);
		System.out.println("Lire N: ");
		int N = sc.nextInt();
		Socket SocketClient = new Socket("localhost", 6666);
		ObjectOutputStream out = new ObjectOutputStream(SocketClient.getOutputStream());
		ServerSocket SocketServer = new ServerSocket(5555);
		Socket connection = SocketServer.accept();
		ObjectInputStream in = new ObjectInputStream(connection.getInputStream());
		boolean run = false;
		while(true){
			if(run){
				System.out.println("Lire N: ");
				N = sc.nextInt();
			}
			run = true;
			out.writeObject(N);
			int Pr = (int)in.readObject();
			int S = (int)in.readObject();
			System.out.println("Produit: "+Pr);
			System.out.println("Somme: "+S);
		}
	}
}
