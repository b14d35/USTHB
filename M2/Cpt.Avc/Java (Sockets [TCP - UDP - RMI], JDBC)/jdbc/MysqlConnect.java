package jdbc;

import java.sql.*;

public class MysqlConnect {
	static Connection conn = null;
	static String url = "jdbc:mysql://localhost:3306/";
	static String dbName = "master2";
	static String driver = "com.mysql.jdbc.Driver";
	static String userName = "root";
	static String password = "";
	
	public static void main(String[] args) {
		System.out.println("MySQL Connect Example.");
		try {
			Class.forName(driver).newInstance();
			conn = DriverManager.getConnection(url+dbName, userName, password);
			System.out.println("Connected to the database.");
			Statement st = conn.createStatement();
			String query = "SELECT * FROM etudiant";
			ResultSet rs = st.executeQuery(query);
			while(rs.next()){
				System.out.println(rs.getString(1)+" "+rs.getString(2)+" "+rs.getString(3));
			}
			conn.close();
			System.out.println("Disconnected from database.");
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
}
