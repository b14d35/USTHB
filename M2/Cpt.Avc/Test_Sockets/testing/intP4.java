package testing;

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.sql.SQLException;
import java.util.ArrayList;

public interface intP4 extends Remote {
	int inserer(int a, String b, String c, int d) throws RemoteException, SQLException;
	int supprimer(int a) throws RemoteException, SQLException;
	int rechercher(int a) throws RemoteException, SQLException;
	int modifier(int a, int b) throws RemoteException, SQLException;
	ArrayList<String> afficher(int a) throws RemoteException, SQLException;
}
