package TestTP;

import java.io.IOException;
import java.net.UnknownHostException;
import java.util.Scanner;

import shortcuts.TCPClient;

public class P2 {
	public static void main(String[] args) throws UnknownHostException, IOException {
		Scanner sc = new Scanner(System.in);
		int M = sc.nextInt();
		sc.close();
		int S2 = M * 2;
		TCPClient clientTCP = new TCPClient("localhost", 6666);
		clientTCP.sendData(M);
		clientTCP.sendData(S2);
	}
}
