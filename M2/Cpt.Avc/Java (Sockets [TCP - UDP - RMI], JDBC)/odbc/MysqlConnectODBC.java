package odbc;

import java.sql.*;

public class MysqlConnectODBC {
	public static void main(String[] args) {
		Connection conn = null;
		String url = "jdbc:odbc:M2IL";
		String dbName = "";
		String userName = "";
		String password = "";
		try{
			conn = DriverManager.getConnection("jdbc:ucanaccess://Test.accdb", userName, password);
			Statement info1 = conn.createStatement();
			ResultSet result2 = info1.executeQuery("SELECT * FROM Table1");
			while(result2.next()){
				System.out.println(result2.getString(1)+" "+result2.getString(2)+" "+result2.getString(3));
			}
			conn.close();
			System.out.println("Disconnected from database");
		} catch (Exception e) {
			System.out.println(e.toString());
			e.printStackTrace();
		}
	}
}
