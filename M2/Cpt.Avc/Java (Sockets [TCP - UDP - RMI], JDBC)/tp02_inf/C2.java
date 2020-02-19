package tp02_inf;

import java.io.IOException;
import java.util.Scanner;

import shortcuts.TCPServer;
import shortcuts.UDPClient;

public class C2 {
	public static void main(String[] args) throws IOException, ClassNotFoundException {
		TCPServer tcpServer = new TCPServer(6666);
		Scanner sc = new Scanner(System.in);
		Integer M, N;
		UDPClient udpClient = new UDPClient("localhost", 8888);
		while(true){
			System.out.println("Lire M: ");
			M = sc.nextInt();
			N = (int) tcpServer.readData();
			udpClient.sendData(N.toString());
			udpClient.sendData(M.toString());
		}
	}
}
