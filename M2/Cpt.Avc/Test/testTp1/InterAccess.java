package testTp1;

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.ArrayList;

public interface InterAccess extends Remote {
	int inserer() throws RemoteException;
	int modifer() throws RemoteException;
	int supprimer() throws RemoteException;
	int rechercher() throws RemoteException;
	ArrayList<String> afficher() throws RemoteException;
}
