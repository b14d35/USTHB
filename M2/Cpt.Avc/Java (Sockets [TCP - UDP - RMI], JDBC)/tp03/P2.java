package tp03;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.rmi.NotBoundException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.sql.SQLException;


public class P2 {
	public static void main(String[] args) throws IOException, ClassNotFoundException, NotBoundException, SQLException {
		RmiP3 rmiServerP3;
		RmiP4 rmiServerP4;
		Registry registryP3, registryP4;
		String Adress = "localhost";
		int PortP3 = 7777, PortP4 = 8888;
		registryP4 = LocateRegistry.getRegistry(Adress, PortP4);
		System.out.println("RMI registry found on port "+PortP4);
		rmiServerP4 = (RmiP4)(registryP4.lookup("rmiServerP4"));
		registryP3 = LocateRegistry.getRegistry(Adress, PortP3);
		System.out.println("RMI registry found on port "+PortP3);
		rmiServerP3 = (RmiP3)(registryP3.lookup("rmiServerP3"));
		ServerSocket SocketServer = new ServerSocket(6666);
		System.out.println("Server TCP started at localhost:6666.");
		Socket connection = SocketServer.accept();
		ObjectInputStream in = new ObjectInputStream(connection.getInputStream());
		ObjectOutputStream out = new ObjectOutputStream(connection.getOutputStream());
		int choice;
		while(true){
			choice = (int) in.readObject();
			switch(choice){
				case 1:
					Etudiant et = (Etudiant) in.readObject();
					out.writeObject(rmiServerP3.insertStudent(et));
					out.writeObject(rmiServerP4.insertStudent(et));
					break;
				case 2:
					int matDel = (int) in.readObject();
					out.writeObject(rmiServerP3.deleteStudent(matDel));
					out.writeObject(rmiServerP4.deleteStudent(matDel));
					break;
				case 3:
					int matSearh = (int) in.readObject();
					out.writeObject(rmiServerP3.searchStudent(matSearh));
					out.writeObject(rmiServerP4.searchStudent(matSearh));
					break;
				default:
					break;
			}
		}
		
	}
}
