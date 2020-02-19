package udp;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Scanner;

public class UDPClient {
	public static void main(String[] args) throws Exception{
		DatagramSocket clientSocket = new DatagramSocket();
		InetAddress IPAdress = InetAddress.getByName("localhost");
		byte[] receiveData = new byte[10];
		byte[] sendData = new byte[10];
		System.out.println("Sentence: ");
		Scanner sc = new Scanner(System.in);
		String sentence = sc.nextLine();
		sendData = sentence.getBytes();
		DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAdress, 8888);
		clientSocket.send(sendPacket);
		DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
		clientSocket.receive(receivePacket);
		String modifiedSentence = new String(receivePacket.getData());
		System.out.println("ORIGINAL SENTENCE: "+ sentence);
		System.out.println("FROM SERVER (IP Server Address "+receivePacket.getAddress().toString()+" Port Server: "+receivePacket.getPort()+")");
		System.out.println("AFTER MODIFICATION: "+ modifiedSentence);
		clientSocket.close();
	}
}
