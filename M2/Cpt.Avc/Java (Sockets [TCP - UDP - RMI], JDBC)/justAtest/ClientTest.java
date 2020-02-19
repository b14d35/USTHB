package justAtest;
import java.io.*;
import java.net.*;
import java.util.Scanner;

import shortcuts.UDPClient;

public class ClientTest {
	public static void main(String[] args) {
		try {
			UDPClient udp = new UDPClient("localhost", 6666);
			System.out.println("Connected to localhost in port 6666");
			Scanner  sc = new Scanner(System.in);
			String message = "";
			while(!message.equals("Exit")){
				message = sc.nextLine();
				udp.sendData(message);
				System.out.println("Client> "+message);
				if(!message.equals("Exit")){
					message = udp.readData();
					System.out.println("Server> "+message);
				}
			}
		} catch (Exception e){
			System.out.println("Exception !!! "+e.toString());
		}
	}
}
