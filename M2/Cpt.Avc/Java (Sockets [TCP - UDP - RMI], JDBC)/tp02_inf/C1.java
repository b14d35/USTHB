package tp02_inf;

import java.io.IOException;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

import shortcuts.TCPClient;

public class C1 {
	public static void main(String[] args) throws UnknownHostException, IOException, ClassNotFoundException {
		TCPClient tcpClient = new TCPClient("localhost", 6666);
		Scanner sc = new Scanner(System.in);
		int N;
		while(true){
			System.out.println("Lire N: ");
			N = sc.nextInt();
			tcpClient.sendData(N);
		}
	}
}
