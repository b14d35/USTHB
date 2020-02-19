// TCP
	// Créer un serveur
	ServerSocket SocketServer = new ServerSocket(6666);
	// Accepter un client
	Socket connection = SocketServer.accept();
	// Envoyer au client
	ObjectOutputStream out = new ObjectOutputStream(connection.getOutputStream());
	out.writeObject("Something");
	// Recevoir du client
	ObjectInputStream in = new ObjectInputStream(connection.getInputStream());
	Object message = (Object) in.readObject();	
	/*______________________________________________________________________________*/
	// Se connecter a un serveur
	Socket SocketClient = new Socket("localhost", 6666);
	// Envoyer au serveur
	ObjectOutputStream out = new ObjectOutputStream(SocketClient.getOutputStream());
	out.writeObject("Something");
	// Recevoir du serveur
	ObjectInputStream in = new ObjectInputStream(SocketClient.getInputStream());
	Object message = (Object) in.readObject();	
	// Sortcuts
		// TCP Server: TCPServer tcpS = new TCPServer(port);
		// TCP Client: TCPClient tcpC = new TCPClient(ip, port);
		// Send: udp.sendData(Object);
		// Receive Object: udp.readData();
//----------------------------------------------------------------------------------------//
// UDP
	// Créer un serveur
	DatagramSocket serverSocket = new DatagramSocket(8888);
	// Recevoir du client
	byte[] receiveData = new byte[10];
	DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
	serverSocket.receive(receivePacket);
	String sentence = new String(receivePacket.getData());
	// Envoyer au client
	InetAddress IPAddress = receivePacket.getAddress();
	int port = receivePacket.getPort();
	sendData = sentence.getBytes();	
	DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, port);
	serverSocket.send(sendPacket);
	// Connecter au serveur
	DatagramSocket clientSocket = new DatagramSocket();
	InetAddress IPAdress = InetAddress.getByName("localhost");
	// Envoyer au serveur
	byte[] sendData = new byte[10];
	sendData = sentence.getBytes();
	DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAdress, 8888);
	clientSocket.send(sendPacket);
	// Recevoir du serveur
	DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
	clientSocket.receive(receivePacket);
	String modifiedSentence = new String(receivePacket.getData());		
	// Recevoir un entier
	int i = Integer.parseInt(modifiedSentence);
	// Shortcuts
		// UDP Server: UDPServer udpS = new UDPServer(port);
		// UDP Client: UDPClient udpC = new UDPClient(ip, port);
		// Send: udp.sendData(string);
		// Receive String: udp.readData();
		// Receive Float: udp.readFloat();
		// Receive Int: udp.readInt();
//-----------------------------------------------------------------------
// RMI
	// Créer d'abord une interface
	public interface interfaceSomething extends Remote {
		// Ajouter les fonctions with throws RemoteException
		// Example
		int exemple() throws RemoteException;
	}
	// Créer un serveur
	public class something extends UnicastRemoteObject implements interfaceSomething{
		String Address = "localhost";
		static int Port = 7777;
		
		public something() throws Exception {
			System.out.println("Adress Serveur= "+Address+", Port= "+Port);
		}
		// Les fonctions
		public static void main(String[] args) {
			try{
				something s = new something();
				System.out.println("Server ready");
				Registry registry = LocateRegistry.createRegistry(Port);
				System.out.println("Created registry on port:"+Port);
				registry.bind("something", s);
			} catch (Exception e) {
				System.out.println(e.toString());
				System.exit(-1);
			}
		}
	}
	// Créer un client
	interfaceSomething rmiServer;
	Registry registry;
	String Adress = "localhost";
	int Port = 7777;
	try {
		registry = LocateRegistry.getRegistry(Adress, Port);
		System.out.println("Registry found on port:"+Port);
		rmiServer = (interfaceSomething) registry.lookup("something");
		// Appeler la fonction
		rmiServer.exemple();
	} catch (Exception e) {
		System.out.println(e.toString());
	}
// Mysql + Access
	static Connection conn = null;
	// Créer la connexion Mysql
	Class.forName("com.mysql.jdbc.Driver").newInstance();
	conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/master2", "root", "");
	// Créer une connexion Access
	conn = DriverManager.getConnection("jdbc:ucanaccess://Test.accdb", "", "");
	// Faire un select
	Statement st = conn.createStatement();
	ResultSet rs = st.executeQuery("Select * from table");
	while(rs.next()){
		System.out.println(rs.getString(1)+"...");
	}
	conn.close();
	// Faire un Insert | Update
	Statement st = conn.createStatement();
	int rs = st.executeUpdate("Update...");
//---------------------------------------------------------------------
// EJB Stateless
	// Interface
	@Remote
	public interface StatelessInf {
		// Methodes to add
	}
	// The Bean
	@Stateless
	public class Bean implements StatelessInf {
		// Write the source code of the methodes
	}
// EJB Stateful
	// Same thing as Stateless But the difference is that in the client the state is keep till he disconnects
// EJB Entity (generally Stateless)
	// Add a file in Meta-Inf named persistence.xml
		<persistence>
			<persistence-unit name="NameHere">
				<jta-data-source>java:/DefaultDS</jta-data-source>
				<properties>
					<property name="hibernate.hbm2ddl.auto" value="update"/>
				</properties>
			</persistence-unit>
		</persistence>
	// Interface
		// If a list is returned must be type List
	// The Bean
	@Stateless
	publi class Bean implements EntityInf {
		@PersistenceContext(unitName="NameHere")
		EntityManager em;
		// Method search: em.find(TypeOfClass.class, id);
		// Method add: Livre b = search(x.getId());if(b == null) em.persist(x);
		// ShowAll: return em.createQuery("From tableName").getResultList();
	}
	// The Type you want
	@Entity
	@Table(name="TheName")
	public class Table implements Serializable {
		@Id
		private int Id;
		// Other attributes
		public Table(){}
		// Add other contructures that have fields
		// Add setters and getters : no setter for ID
		// Add a toString
	}
// The client Side
	// Create the Context
	Logger.getRootLogger().setLevel(Level.OFF);
	Properties props = System.getProperties();
	props.put(Context.INITIAL_CONTEXT_FACTORY, "org.jnp.interfaces.NamingContextFactory");
	props.put(Context.URL_PKG_PREFIXES, "org.jboss.naming:org.jnp.interfaces");
	props.put(Context.PROVIDER_URL, "jnp://localhost:1099");
	Context ctx = new InitialContext(props);
	// Or use the shortcut I created
	Context ctx = ContextEJB.getInitialContext();
	// Next
	TheInterfaceName something = (TheInterfaceName) ctx.lookup("ThebeanName/remote");
	// Then you can make the calls as you wish to the methods
//---------------------------------------------------------------
// You create your files in web-content
// To execute Java code in JSP files we use <% code %>
// To receive the data in JSP file, you need to use request.getParameter("nameParam")