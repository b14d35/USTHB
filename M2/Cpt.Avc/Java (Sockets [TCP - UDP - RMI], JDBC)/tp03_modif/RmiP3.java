package tp03_modif;

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.sql.SQLException;

public interface RmiP3 extends Remote{
	boolean insertStudent(Etudiant student) throws RemoteException, SQLException;
	boolean deleteStudent(int matricule) throws RemoteException, SQLException;
	Etudiant searchStudent(int matricule) throws RemoteException, SQLException;
}
