package tp02_inf02;

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.ArrayList;

public interface C1_Interface extends Remote{
	void Affichage(boolean a, ArrayList<Integer> b) throws RemoteException;
}
