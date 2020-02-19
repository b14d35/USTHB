package tp02_inf02;

import java.rmi.*;

public interface C4_Interface extends Remote {
	void Produit(int n, int m) throws RemoteException;
	void Cubique(int n, int m) throws RemoteException;
	void Amicaux(boolean a) throws RemoteException;
}
