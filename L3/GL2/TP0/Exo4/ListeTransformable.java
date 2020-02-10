import java.util.Iterator;
import java.util.LinkedList;

public class ListeTransformable extends LinkedList{
	public ListeTransformable transforme(Transformation f) {
		ListeTransformable t = new ListeTransformable();
		Iterator i = this.iterator();
		while(i.hasNext())
			t.add(f.transfo(i.next()));
		return t;
	}
}
