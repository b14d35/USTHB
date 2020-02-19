package testTp1;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.UnknownHostException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class P1 {
	public static void main(String[] args) {
		Connection conn = null;
		try {
			Class.forName("com.mysql.jdbc.Driver").newInstance();
			conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/master2", "root", "");
			
			Statement st = conn.createStatement();
			ResultSet rs = st.executeQuery("Select num from test where id=1");
			Integer N = 0;
			while(rs.next()){
				N = rs.getInt(1);
			}
			DatagramSocket clientSocket = new DatagramSocket();
			InetAddress IPAdress = InetAddress.getByName("localhost");
			byte[] sendData = new byte[10];
			sendData = N.toString().getBytes();
			DatagramPacket dp = new DatagramPacket(sendData, sendData.length, IPAdress, 8888);
			clientSocket.send(dp);
		} catch (InstantiationException | IllegalAccessException | ClassNotFoundException | SQLException e) {
			e.printStackTrace();
		} catch (SocketException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (UnknownHostException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
}
