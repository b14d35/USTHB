package EJBClient;

import java.util.Properties;

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;

import org.apache.log4j.Level;
import org.apache.log4j.Logger;

public class ContextEJB {
	public static Context getInitialContext() throws NamingException{
		Logger.getRootLogger().setLevel(Level.OFF);
		Properties props = System.getProperties();
		props.put(Context.INITIAL_CONTEXT_FACTORY, "org.jnp.interfaces.NamingContextFactory");
		props.put(Context.URL_PKG_PREFIXES, "org.jboss.naming:org.jnp.interfaces");
		props.put(Context.PROVIDER_URL, "jnp://localhost:1099");
		return new InitialContext(props);
	}
}
