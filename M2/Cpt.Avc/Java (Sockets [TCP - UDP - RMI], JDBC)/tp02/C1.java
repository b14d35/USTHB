package tp02;

import java.io.IOException;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.Scanner;

public class C1 {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		System.out.println("Lire N: ");
		int N = sc.nextInt();
		Socket SocketClient = new Socket("localhost", 6666);
		System.out.println("Attente de connexion a P2");
		ObjectOutputStream out = new ObjectOutputStream(SocketClient.getOutputStream());
		out.writeObject(N);
		out.close();
		SocketClient.close();
	}
}
