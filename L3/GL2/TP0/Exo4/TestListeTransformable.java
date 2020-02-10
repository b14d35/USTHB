
public class TestListeTransformable {
	public static void main(String[] args) {
		ListeTransformable lt1 = new ListeTransformable();
		for(int i=0;i<10;i++)
			lt1.addLast(new Integer(i));
		System.out.println(lt1);
		ListeTransformable lt2 = new lt1.transforme(new Transformation() {
			public Object transfo(Object o) {
				int x = ((Integer) o).intValue();
				return new Integer(x*x);
			}
		});
		System.out.println(lt2);
	}
}
