package tp02_modif;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface C4_Interface extends Remote {
	void Produit(int n, int m) throws RemoteException;
	void Cubique(int n, int m) throws RemoteException;
	void Amicaux(boolean a) throws RemoteException;
}