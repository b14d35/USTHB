package tp02_modif;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;
import java.rmi.AlreadyBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.ArrayList;
import java.util.Scanner;

import tp02_modif.C1_Interface;

public class C1 extends java.rmi.server.UnicastRemoteObject implements C1_Interface{
	String Address = "localhost";
	static int Port = 8989;
	static boolean read = false;
	public C1() throws RemoteException{
		System.out.println("Adress Serveur= "+Address+", Port= "+Port);
	}
	
	public void Affichage(boolean a, ArrayList<Integer> b) throws RemoteException {
		if(a){
			System.out.println("Les nombres sont amicaux");
		}else{
			System.out.println("Les nombres ne sont pas amicaux");
		}
		if(b.size()>0){
			System.out.println("--------------------------");
			System.out.println("Les entiers cubiques sont:");
			System.out.println(b);
			System.out.println("__________________________");
		}
		read = false;
	}
	
	public static void main(String[] args) throws UnknownHostException, IOException, AlreadyBoundException, ClassNotFoundException {
		Socket SocketClient = new Socket("localhost", 6666);
		ObjectOutputStream out = new ObjectOutputStream(SocketClient.getOutputStream());
		ServerSocket SocketServerP1 = new ServerSocket(7890);
		Socket connectionP1 = SocketServerP1.accept();
		ObjectInputStream inP1 = new ObjectInputStream(connectionP1.getInputStream());
		int N;
		C1 s = new C1();
		System.out.println("Le serveur est pret");
		Registry registry = LocateRegistry.createRegistry(Port);
		System.out.println("Created RMI registry on port "+Port);
		registry.bind("rmiServerC1", s);
		while(true){
			while(read);
			N  = (int)inP1.readObject();
			read = true;
			out.writeObject(N);
		}
	}
}