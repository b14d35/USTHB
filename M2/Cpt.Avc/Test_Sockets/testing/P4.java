package testing;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

public class P4 extends UnicastRemoteObject implements intP4 {
	String Address = "localhost";
	static int Port = 6666;
	static Connection conn = null;
	public P4() throws Exception {
		System.out.println("Adress Serveur= "+Address+", Port= "+Port);
	}
	public static void main(String[] args) throws Exception {
		P4 s = new P4();
		System.out.println("Server ready");
		Registry registry = LocateRegistry.createRegistry(Port);
		System.out.println("Created registry on port:"+Port);
		registry.bind("P4", s);
		conn = DriverManager.getConnection("jdbc:ucanaccess://produit.accdb", "", "");
	}
	@Override
	public int inserer(int a, String b, String c, int d) throws RemoteException, SQLException {
		Statement st = conn.createStatement();
		int rs = st.executeUpdate("INSERT INTO produit (id, designation, type, quantite) VALUES ("+a+",'"+b+"','"+c+"',"+d+")");
		return rs;
	}
	@Override
	public int supprimer(int a) throws RemoteException, SQLException {
		Statement st = conn.createStatement();
		int rs = st.executeUpdate("DELETE FROM produit WHERE id="+a);
		return rs;
	}
	@Override
	public int rechercher(int a) throws RemoteException, SQLException {
		Statement st = conn.createStatement();
		ResultSet rs = st.executeQuery("Select * from produit where id="+a);
		while(rs.next()){
			rs.close();
			return 1;
		}
		return 0;
	}
	@Override
	public int modifier(int a, int b) throws RemoteException, SQLException {
		Statement st = conn.createStatement();
		int rs = st.executeUpdate("UPDATE produit SET quantite="+b+" WHERE id="+a);
		return rs;
	}
	@Override
	public ArrayList<String> afficher(int a) throws RemoteException, SQLException {
		ArrayList<String> res = new ArrayList<String>();
		Statement st = conn.createStatement();
		ResultSet rs = st.executeQuery("Select designation, quantite from produit where id="+a);
		while(rs.next()){
			res.add(rs.getString("designation"));
			res.add(rs.getString("quantite"));
		}
		return res;
	}
}
