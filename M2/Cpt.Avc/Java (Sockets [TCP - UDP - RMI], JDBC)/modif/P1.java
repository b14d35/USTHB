package modif;

import java.io.IOException;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

public class P1 {
	public static void main(String[] args) throws UnknownHostException, IOException {
		Scanner sc = new Scanner(System.in);
		// Program 1
		Socket SocketClient = new Socket("localhost", 3456);
		Socket SocketClient2 = new Socket("localhost", 4567);
		ObjectOutputStream out = new ObjectOutputStream(SocketClient.getOutputStream());
		ObjectOutputStream out2 = new ObjectOutputStream(SocketClient2.getOutputStream());
		// Program 2
		Socket SocketClient3 = new Socket("localhost", 7890);
		Socket SocketClient4 = new Socket("localhost", 8901);
		ObjectOutputStream out3 = new ObjectOutputStream(SocketClient3.getOutputStream());
		ObjectOutputStream out4 = new ObjectOutputStream(SocketClient4.getOutputStream());
		 int N, M;
		 while(true){
		 	System.out.println("Lire N: ");
			N = sc.nextInt();
			System.out.println("Lire M: ");
			M = sc.nextInt();
		 	out.writeObject(N);
			out2.writeObject(M);
			out3.writeObject(N);
			out4.writeObject(M);
		 }
	}
}
