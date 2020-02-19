package tp01_2;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class C3 {
	
	private static boolean Premier(int x){
		for(int i=2; i<x; i++){
			if(x%i == 0){
				return false;
			}
		}
		return true;
	}
	
	private static int Produit(int S){
		int P = 1;
		for(int i=2; i<=S; i++){
			if (Premier(i)){
				P *= i;
			}
		}
		return P;
	}
	public static void main(String[] args) throws IOException, ClassNotFoundException {
		ServerSocket SocketServer = new ServerSocket(7777);
		Socket connection = SocketServer.accept();
		ObjectInputStream in = new ObjectInputStream(connection.getInputStream());
		Socket SocketClient = new Socket("localhost", 5555);
		ObjectOutputStream out = new ObjectOutputStream(SocketClient.getOutputStream());
		while(true){
			int N = (int)in.readObject();
			int M = (int)in.readObject();
			int S = N+M;
			int Pr = Produit(S);
			out.writeObject(Pr);
			out.writeObject(S);
		}
	}
}
