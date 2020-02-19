package tp01_2;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class C2 {
	public static void main(String[] args) throws IOException, ClassNotFoundException {
		Scanner sc = new Scanner(System.in);
		ServerSocket SocketServer = new ServerSocket(6666);
		Socket connection = SocketServer.accept();
		ObjectInputStream in = new ObjectInputStream(connection.getInputStream());
		Socket SocketClient = new Socket("localhost", 7777);
		ObjectOutputStream out = new ObjectOutputStream(SocketClient.getOutputStream());
		while(true){
			System.out.println("Lire M: ");
			int M = sc.nextInt();
			int N = (int)in.readObject();
			out.writeObject(N);
			out.writeObject(M);
		}
	}
}
