package shortcuts;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class TCPServer {
	private ServerSocket server;
	private Socket client;
	private ObjectInputStream in;
	private ObjectOutputStream out;
	
	public TCPServer(int port) throws IOException {
		server = new ServerSocket(port);
		client = server.accept();
	}
	
	public void sendData(Object o) throws IOException{
		if (out == null){
			out = new ObjectOutputStream(client.getOutputStream());
		}
		out.writeObject(o);
	}
	
	public Object readData() throws IOException, ClassNotFoundException {
		if (in == null){
			in = new ObjectInputStream(client.getInputStream());
		}
		return in.readObject();
	}
}
