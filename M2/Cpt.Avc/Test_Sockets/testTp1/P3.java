package testTp1;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;


public class P3 extends UnicastRemoteObject implements InterMysql {
	String Address = "localhost";
	static int Port = 7777;
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
			
			
		} catch (Exception e) {
			System.out.println(e.toString());
			System.exit(-1);
		}
	}
	@Override
	public void calcul(int M) throws RemoteException {
		int S = M * 3;
		try {
			Class.forName("com.mysql.jdbc.Driver").newInstance();
			Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/master2", "root", "");
			Statement st = conn.createStatement();
			st.executeUpdate("INSERT INTO test (id, num) VALUES (2, "+M+")");
			st.executeUpdate("INSERT INTO test (id, num) VALUES (3, "+S+")");
		} catch (InstantiationException | IllegalAccessException | ClassNotFoundException e) {
			e.printStackTrace();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
}
