package tp03_modif;

import java.rmi.AlreadyBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class P4 extends UnicastRemoteObject implements RmiP4{
	static Connection conn = null;
	static String url = "jdbc:odbc:M2IL";
	static String dbName = "";
	static String userName = "";
	static String password = "";
	
	String Address = "localhost";
	static int Port = 8888;
	
	protected P4() throws RemoteException {
		System.out.println("Adress Serveur= "+Address+", Port= "+Port);
	}
	
	public boolean insertStudent(Etudiant student) throws RemoteException, SQLException {
		Statement st = conn.createStatement();
		String query = "INSERT INTO Etudiant VALUES('"+student.getNom()+"', '"+student.getPrenom()+"', "+student.getMat()+")";
		int rs = st.executeUpdate(query);
		return rs != 0;
	}

	public boolean deleteStudent(int matricule) throws RemoteException, SQLException {
		Statement st = conn.createStatement();
		String query = "DELETE FROM Etudiant WHERE mat="+matricule;
		int rs = st.executeUpdate(query);
		return rs != 0;
	}
	
	public Etudiant searchStudent(int matricule) throws RemoteException, SQLException {
		Statement st = conn.createStatement();
		String query = "SELECT * FROM Etudiant WHERE mat="+matricule;
		ResultSet  rs = st.executeQuery(query);
		Etudiant et = null;
		while(rs.next()){
			et = new Etudiant(rs.getInt("mat"), rs.getString("nom"), rs.getString("prenom"));
			return et;
		}
		return et;
	}
	
	public static void main(String[] args) throws RemoteException, AlreadyBoundException, SQLException {
		conn = DriverManager.getConnection("jdbc:ucanaccess://master2.accdb", userName, password);
		P4 s = new P4();
		System.out.println("Serveur P4 is ready.");
		Registry registry = LocateRegistry.createRegistry(Port);
		System.out.println("Created RMI registry on port "+Port);
		registry.bind("rmiServerP4", s);
	}
	
}
