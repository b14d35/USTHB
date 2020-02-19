package jdbc;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class Exemple {
	final String url = "jdbc:mysql://localhost:3306/pfe";
	void loadDriver() throws ClassNotFoundException{
		Class.forName("com.mysql.jdbc.Driver");
	}
	public void listUsers() throws SQLException{
		Connection conn = null;
		try {
			conn = DriverManager.getConnection(url, "root", "");
			Statement st = conn.createStatement();
			String query = "SELECT id, email, password FROM users ORDER BY id";
			ResultSet rs = st.executeQuery(query);
			while(rs.next()){
				System.out.println(rs.getInt(1)+" "+rs.getString("email")+" "+rs.getString(3));
			}
		} catch (Exception e) {
			System.out.println(e.getMessage());
		} finally {
			if(conn != null){
				conn.close();
			}
		}
	}
	public static void main(String[] args) {
		Exemple ex = new Exemple();
		try{
			ex.loadDriver();
			ex.listUsers();
		} catch (ClassNotFoundException e){
			System.out.println("JDBC Driver not found!");
		} catch (SQLException e){
			System.out.println("SQLException: "+e.getMessage());
			System.out.println("SQLState: "+e.getSQLState());
			System.out.println("VendorError: "+e.getErrorCode());
			e.printStackTrace();
		} catch (Exception e){
			e.printStackTrace();
		}
		
	}
}
