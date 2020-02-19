package shortcuts;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;

public class UDPServer {
	private DatagramSocket server;
	private InetAddress IPclient;
	private DatagramPacket in, out;
	private byte[] read, send;
	private int port;
	
	public UDPServer(int port) throws SocketException{
		server = new DatagramSocket(port);
	}
	
	public void sendData(String data) throws IOException{
		IPclient = in.getAddress();
		port = in.getPort();
		send = new byte[10];
		send = data.getBytes();
		out = new DatagramPacket(send, send.length, IPclient, port);
		server.send(out);
	}
	
	public String readData() throws IOException{
		read = new byte[10];
		in = new DatagramPacket(read, read.length);
		server.receive(in);
		return new String(in.getData()).trim();
	}
	
	public int readInt() throws NumberFormatException, IOException{
		return Integer.parseInt(readData());
	}
	
	public float readFloat() throws NumberFormatException, IOException{
		return Float.parseFloat(readData());
	}
}
