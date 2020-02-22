package testing;

import java.io.IOException;
import java.rmi.NotBoundException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.sql.SQLException;
import java.util.ArrayList;

import shortcuts.UDPServer;

public class P2 {
	public static void main(String[] args) throws IOException, NotBoundException, SQLException {
		UDPServer udpServer = new UDPServer(8888);
		intP3 intP3;
		intP4 intP4;
		Registry regP3, regP4;
		String Adress = "localhost";
		int PortP3 = 7777, PortP4=6666;
		regP3 = LocateRegistry.getRegistry(Adress, PortP3);
		System.out.println("Registry found on port:"+PortP3);
		intP3 = (intP3) regP3.lookup("P3");
		regP4 = LocateRegistry.getRegistry(Adress, PortP4);
		System.out.println("Registry found on port:"+PortP4);
		intP4 = (intP4) regP4.lookup("P4");
		while(true){
			int choix = udpServer.readInt();
			System.out.println(choix);
			switch(choix){
				case 1:
					int id = udpServer.readInt();
					String designation = udpServer.readData();
					String type = udpServer.readData();
					int quantite = udpServer.readInt();
					System.out.println(quantite);
					Integer ins3 = intP3.inserer(id, designation, type, quantite);
					Integer ins4 = intP4.inserer(id, designation, type, quantite);
					udpServer.sendData(ins3.toString());
					udpServer.sendData(ins4.toString());
					break;
				case 2:
					
					int idS = udpServer.readInt();
					Integer suppP3 = intP3.supprimer(idS);
					Integer suppP4 = intP4.supprimer(idS);
					udpServer.sendData(suppP3.toString());
					udpServer.sendData(suppP4.toString());
					break;
				case 3:
					int idR = udpServer.readInt();
					Integer rechP3 = intP3.supprimer(idR);
					Integer rechP4 = intP4.supprimer(idR);
					udpServer.sendData(rechP3.toString());
					udpServer.sendData(rechP4.toString());
					break;
				case 4:
					int idM = udpServer.readInt();
					int newQ = udpServer.readInt();
					Integer chgP3 = intP3.modifier(idM, newQ);
					Integer chgP4 = intP4.modifier(idM, newQ);
					udpServer.sendData(chgP3.toString());
					udpServer.sendData(chgP4.toString());
					break;
				case 5:
					int idF = udpServer.readInt();
					ArrayList<String> resP3 = intP3.afficher(idF);
					ArrayList<String> resP4 = intP4.afficher(idF);
					if(resP3.size() == 2){
						udpServer.sendData(resP3.get(0).toString());
						udpServer.sendData(resP3.get(1).toString());
					} else {
						udpServer.sendData("null".toString());
						udpServer.sendData("null".toString());
					}
					if(resP4.size() == 2){
						udpServer.sendData(resP4.get(0).toString());
						udpServer.sendData(resP4.get(1).toString());
					} else {
						udpServer.sendData("null".toString());
						udpServer.sendData("null".toString());
					}
					break;
			}
		}
	}
}
