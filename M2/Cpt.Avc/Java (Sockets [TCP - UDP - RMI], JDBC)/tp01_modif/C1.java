package tp01_modif;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class C1 {
	public static void main(String[] args) throws IOException, ClassNotFoundException {
		Socket SocketClient = new Socket("localhost", 6667);
		ServerSocket SocketServerP1 = new ServerSocket(3456);
		Socket connectionP1 = SocketServerP1.accept();
		ObjectInputStream inP1 = new ObjectInputStream(connectionP1.getInputStream());
		int N = (int)inP1.readObject();
		ObjectOutputStream out = new ObjectOutputStream(SocketClient.getOutputStream());
		ServerSocket SocketServer = new ServerSocket(5556);
		Socket connection = SocketServer.accept();
		ObjectInputStream in = new ObjectInputStream(connection.getInputStream());
		boolean run = false;
		while(true){
			if(run){
				N = (int)inP1.readObject();
			}
			run = true;
			out.writeObject(N);
			double Pr = (double)in.readObject();
			int S = (int)in.readObject();
			System.out.println("Produit: "+Pr);
			System.out.println("Somme: "+S);
		}
	}
}
