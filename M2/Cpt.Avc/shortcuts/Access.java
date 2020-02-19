package shortcuts;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

// Not fully finished

public class Access {
	private Connection conn;
	
	public Access(String path) throws SQLException{
		conn = DriverManager.getConnection("jdbc:ucanaccess://"+path, "", "");
	}
	
	public boolean updQuery(String query) throws SQLException{
		Statement st = conn.createStatement();
		int rs = st.executeUpdate(query);
		return rs != 0;
	}
	
	public ArrayList<Object> execQuery(String query) throws SQLException{
		Statement st = conn.createStatement();
		ResultSet  rs = st.executeQuery(query);
		ArrayList<Object> et = null;
		while(rs.next()){
			// Add re.getSomething
		}
		return et;
	}
}
