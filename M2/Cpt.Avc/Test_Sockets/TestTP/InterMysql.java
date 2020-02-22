package TestTP;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface InterMysql extends Remote {
	void recevoir(int N, int S1) throws RemoteException;
}
