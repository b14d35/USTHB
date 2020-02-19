package tp01_modif;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class C2 {
	public static void main(String[] args) throws IOException, ClassNotFoundException {
		ServerSocket SocketServer = new ServerSocket(6667);
		Socket connection = SocketServer.accept();
		ServerSocket SocketServerP1 = new ServerSocket(4567);
		Socket connectionP1 = SocketServerP1.accept();
		ObjectInputStream inP1 = new ObjectInputStream(connectionP1.getInputStream());
		int N, M;
		ObjectInputStream in = new ObjectInputStream(connection.getInputStream());
		Socket SocketClient = new Socket("localhost", 7776);
		ObjectOutputStream out = new ObjectOutputStream(SocketClient.getOutputStream());
		while(true){
			M = (int)inP1.readObject();
			N = (int)in.readObject();
			out.writeObject(N);
			out.writeObject(M);
		}
	}
}
