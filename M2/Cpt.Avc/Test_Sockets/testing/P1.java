package testing;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

import shortcuts.Menu;
import shortcuts.UDPClient;

public class P1 {
	public static void main(String[] args) throws IOException {
		UDPClient udpClient = new UDPClient("localhost", 8888);
		Scanner sc = new Scanner(System.in);
		ArrayList<String> liste = new ArrayList<String>();
		liste.add("insertion");
		liste.add("suppression");
		liste.add("recherche");
		liste.add("modification");
		liste.add("affichage");
		Menu menu = new Menu(liste);
		while(true){
			menu.show();
			Integer choix = sc.nextInt();
			udpClient.sendData(choix.toString());
			switch(choix){
				case 1:
					Integer id = sc.nextInt();
					udpClient.sendData(id.toString());
					String designation = sc.next();
					udpClient.sendData(designation.toString());
					String type = sc.next();
					udpClient.sendData(type.toString());
					Integer quantite = sc.nextInt();
					udpClient.sendData(quantite.toString());		
					int ajP3 = udpClient.readInt();		
					int ajP4 = udpClient.readInt();
					System.out.println(ajP3);
					System.out.println(ajP4);
					break;
				case 2:
					Integer idS = sc.nextInt();
					udpClient.sendData(idS.toString());		
					int suppP3 = udpClient.readInt();		
					int suppP4 = udpClient.readInt();
					System.out.println(suppP3);
					System.out.println(suppP4);
					break;
				case 3:
					Integer idR = sc.nextInt();
					udpClient.sendData(idR.toString());		
					int rechP3 = udpClient.readInt();		
					int rechP4 = udpClient.readInt();
					System.out.println(rechP3);
					System.out.println(rechP4);
					break;
				case 4:
					Integer idM = sc.nextInt();
					udpClient.sendData(idM.toString());
					Integer newQ = sc.nextInt();
					udpClient.sendData(newQ.toString());		
					int modP3 = udpClient.readInt();		
					int modP4 = udpClient.readInt();
					System.out.println(modP3);
					System.out.println(modP4);
					break;
				case 5:
					Integer idF = sc.nextInt();
					udpClient.sendData(idF.toString());		
					String a = udpClient.readData();		
					String b = udpClient.readData();
					String c = udpClient.readData();
					String d = udpClient.readData();
					System.out.println(a+" "+b);
					System.out.println(c+" "+d);
					break;
			}
		}
	}
}
