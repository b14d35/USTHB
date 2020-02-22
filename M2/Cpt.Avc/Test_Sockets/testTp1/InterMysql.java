package testTp1;

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.ArrayList;

public interface InterMysql extends Remote {
	void calcul(int M) throws RemoteException;
}
