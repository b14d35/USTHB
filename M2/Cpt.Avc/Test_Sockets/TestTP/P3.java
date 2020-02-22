package TestTP;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

import shortcuts.TCPServer;


public class P3  extends UnicastRemoteObject implements InterMysql {
	String Address = "localhost";
	static int Port = 7777;
	static int N, S1;
	public P3() throws RemoteException{
		System.out.println("Adress Serveur= "+Address+", Port= "+Port);
	}
	public static void main(String[] args) {
		try {
			P3 s = new P3();
			System.out.println("Hello Server is ready.");
			Registry registry = LocateRegistry.createRegistry(Port);
			System.out.println("Created RMI registry on port "+Port);
			registry.bind("rmiServer", s);
			TCPServer serverTCP = new TCPServer(6666);
			int M = (int) serverTCP.readData();
			int S2 = (int) serverTCP.readData();
			Class.forName("com.mysql.jdbc.Driver").newInstance();
			Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/master2", "root", "");
			Statement st1 = conn.createStatement();
			st1.executeUpdate("INSERT INTO test (id, num) values ("+N+","+S1+")");
			st1.executeUpdate("INSERT INTO test (id, num) values ("+M+","+S2+")");
			st1.executeUpdate("INSERT INTO test (id, num) values ("+(N+M)+","+(S1+S2)+")");
		} catch (Exception e) {
			System.out.println(e.toString());
			System.exit(-1);
		}
	}
	@Override
	public void recevoir(int N, int S1) throws RemoteException {
		P3.N = N;
		P3.S1 = S1;
	}
}
