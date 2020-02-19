package shortcuts;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.net.UnknownHostException;

public class TCPClient {
	private Socket client;
	private ObjectInputStream in;
	private ObjectOutputStream out;
	
	public TCPClient(String ip, int port) throws UnknownHostException, IOException{
		client = new Socket(ip, port);
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
