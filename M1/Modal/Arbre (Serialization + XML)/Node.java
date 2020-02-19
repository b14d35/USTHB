import java.io.Serializable;

public class Node<T> implements Serializable{
	private T val;
	private int fg, fd;
	public Node(T val) {
		this.val = val;
		this.fg = -1;
		this.fd = -1;
	}
	public T getVal() {
		return val;
	}
	public void setVal(T val) {
		this.val = val;
	}
	public int getFg() {
		return fg;
	}
	public void setFg(int fg) {
		this.fg = fg;
	}
	public int getFd() {
		return fd;
	}
	public void setFd(int fd) {
		this.fd = fd;
	}
	@Override
	public String toString() {
		return "[ " + this.fg + " | " + this.val + " | " + this.fd + " ]";
	}
}
