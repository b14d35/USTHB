import java.util.Collection;
import java.util.Iterator;

public class TestSelection implements CritereSelection{
	static Collection selection(Collection source, CritereSelection critere) {
		Iterator i = source.iterator();
		Class classe = source.getClass();
		
		Collection y = null;
		try {
			y = (Collection) classe.newInstance();
			while(i.hasNext()){
				Object o = i.next();
				if(critere.ok(o)) y.add(o);
			}
		} catch (InstantiationException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		for(Object x : source){
			if(critere.ok(x)) y.add(x);	
		}
		return y;
	}
	@Override
	public boolean ok(Object x) {
		if (x instanceof Integer) {
			Integer y = (Integer) x;
			if(y%3==0) return true;
		}
		return false;
	}
}
