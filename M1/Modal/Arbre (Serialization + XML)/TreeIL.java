import java.io.BufferedWriter;
import java.io.EOFException;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;

public class TreeIL<T extends Comparable<T>>{
	private ArrayList<Node<T>> racine = new ArrayList<Node<T>>();
	
	boolean insert(T value){
		int size = racine.size();
		Node<T> ins = new Node<T>(value);
		if(!racine.add(ins)){
			return false;
		}
		if(size > 0){
			int ind = 0;
			Node<T> cmp = null;
			while(true){
				cmp = racine.get(ind);
				if(cmp.getVal().compareTo(value)<=0){
					if(cmp.getFd() == -1){
						break;
					}else{
						ind = cmp.getFd();
					}
				}else{
					if(cmp.getFg() == -1){
						break;
					}else{
						ind = cmp.getFg();
					}
				}
			}
			if(cmp.getVal().compareTo(value)<0){
				cmp.setFd(size);
			}else{
				cmp.setFg(size);
			}
		}
		return true;
	}
	
	boolean find(T val){
		for (Node<T> node : racine) {
			if(node.getVal() == val){
				return true;
			}
		}
		return false;
	}
	
	boolean saveXML(){
		try {
			FileWriter f = new FileWriter("tree.xml");
			BufferedWriter bw = new BufferedWriter(f);
			bw.write("<?xml version = \"1.0\"?>\n");
			bw.write("<TreeIL Type=\"IL\" Size=\""+racine.size()+"\">");
			bw.newLine();
			int i = 0;
			for (Node<T> node: racine) {
				bw.write("\t<Node Index=\""+i+"\">\n");
				bw.write("\t\t<Value>"+node.getVal()+"</Value>\n");
				bw.write("\t\t<Fg>"+node.getFg()+"</Fg>\n");
				bw.write("\t\t<Fd>"+node.getFd()+"</Fd>\n");
				bw.write("\t</Node>\n");
				i++;
			}
			bw.write("</TreeIL>");
			bw.close();
		} catch (IOException e){
			return false;
		}
		return true;
	}
	
	boolean saveSER(){
		try {
			FileOutputStream fs = new FileOutputStream("tree.ser");
			ObjectOutputStream os = new ObjectOutputStream(fs);
			for (Node<T> node : racine) {
				os.writeObject(node);
			}
			os.close();
		} catch (Exception e) {
			return false;
		}
		return true;
	}
	
	boolean restore(){
		try {
			FileInputStream fis = new FileInputStream("tree.ser");
			ObjectInputStream ois = new ObjectInputStream(fis);
			racine.removeAll(racine);
			Object node = null;
			while((node = ois.readObject()) != null){
				if(node instanceof Node){
					racine.add((Node)node);
				}
			}
			ois.close();
		} catch (EOFException ex){
			System.out.println("End Of File reached");
		} catch (Exception e) {
			return false;
		}
		return true;
	}
	
	void display(){
		for (Node node : racine) {
			System.out.println(node);
		}
	}
	
	int taille(){
		return racine.size();
	}
	
}
