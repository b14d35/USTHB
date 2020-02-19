package shortcuts;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.UnknownHostException;

public class UDPClient {
	private DatagramSocket client;
	private InetAddress IPserver;
	private DatagramPacket in, out;
	private byte[] read, send;
	private int port;
	
	public UDPClient(String ip, int port) throws SocketException, UnknownHostException{
		client = new DatagramSocket();
		IPserver = InetAddress.getByName(ip);
		this.port = port;
	}
	
	public void sendData(String data) throws IOException{
		send = new byte[10];
		send = data.getBytes();
		out = new DatagramPacket(send, send.length, IPserver, port);
		client.send(out);
	}
	
	public String readData() throws IOException{
		read = new byte[10];
		in = new DatagramPacket(read, read.length);
		client.receive(in);
		return new String(in.getData()).trim();
	}
	
	public int readInt() throws NumberFormatException, IOException{
		return Integer.parseInt(readData());
	}
	
	public float readFloat() throws NumberFormatException, IOException{
		return Float.parseFloat(readData());
	}
	
}
