package justAtest;
import java.io.*;
import java.net.*;
import java.util.Scanner;

import shortcuts.UDPServer;

public class ServerTest {
	public static void main(String[] args) {
		try {
			UDPServer udp = new UDPServer(6666);
			System.out.println("Waiting for onnection");
			Scanner  sc = new Scanner(System.in);
			String message = "";
			while(!message.equals("Exit")){
				message = udp.readData();
				System.out.println("Client> "+message);
				if(!message.equals("Exit")){
					message = sc.nextLine();
					udp.sendData(message);
					System.out.println("Server> "+message);
				}
			}
		} catch (Exception e) {
			System.out.println("Exception !!! "+e.toString());
		}
	}
}
