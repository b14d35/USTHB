package rmi;
import java.rmi.*;

public interface interfaceRMI extends Remote{
	void receiveMessage(String x) throws RemoteException;
	int calcul(int a, int b) throws RemoteException;
}
