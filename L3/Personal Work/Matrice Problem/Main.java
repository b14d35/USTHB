
import java.util.ArrayList;
import java.util.LinkedList;

public class Main {
public static void main(String[] args) {
ArrayList<Case> tab = new ArrayList<Case>();
LinkedList<String> solutions = new LinkedList<String>();
for(int i=1;i<7;i++){
tab.add(new Case(i));
}
Case a = new Case(1);
Case h = new Case(2);
Case o = new Case(3);
Case v = new Case(4);
Case a3 = new Case(5);
Case a0 = new Case(6);
int total=0;
for (Case b : tab) {
	if(Case.line(a,b) && Case.line(b,h))
for (Case c : tab) {
	if(Case.line(a,b,c) && Case.line(c,o))
for (Case d : tab) {
	if(Case.line(a,b,c,d) && Case.line(d,v))
for (Case e : tab) {
	if(Case.line(a,b,c,d,e) && Case.line(e,a3))
for (Case f : tab) {
	if(Case.line(a,b,c,d,e,f) && Case.line(f,a0))
for (Case g : tab) {
	if(Case.line(a,g,h))
for (Case i : tab) {
	if(Case.line(g,h,i) && Case.line(c,i,o))
for (Case j : tab) {
	if(Case.line(g,h,i,j) && Case.line(d,j,v))
for (Case k : tab) {
	if(Case.line(g,h,i,j,k) && Case.line(e,k,a3))
for (Case l : tab) {
	if(Case.line(g,h,i,j,k,l) && Case.line(f,l,a0))
for (Case m : tab) {
	if(Case.line(a,g,m) && Case.line(m,o))
for (Case n : tab) {
	if(Case.line(m,n,o) && Case.line(b,h,n))
for (Case p : tab) {
	if(Case.line(m,n,o,p) && Case.line(d,j,p,v))
for (Case q : tab) {
	if(Case.line(m,n,o,p,q) && Case.line(e,k,q,a3))
for (Case r : tab) {
	if(Case.line(m,n,o,p,q,r) && Case.line(f,l,r,a0))
for (Case s : tab) {
	if(Case.line(a,g,m,s) && Case.line(s,v))
for (Case t : tab) {
	if(Case.line(s,t,v) && Case.line(b,h,n,t))
for (Case u : tab) {
	if(Case.line(s,t,u,v) && Case.line(c,i,o,u))
for (Case w : tab) {
	if(Case.line(s,t,u,v,w) && Case.line(e,k,q,w))
for (Case x : tab) {
	if(Case.line(s,t,u,v,w,x) && Case.line(f,l,r,x,a0))
for (Case y : tab) {
	if(Case.line(a,g,m,s,y) && Case.line(y,a3))
for (Case z : tab) {
	if(Case.line(y,a3,z) && Case.line(b,h,n,t,z))
for (Case a1 : tab) {
	if(Case.line(y,z,a1,a3) && Case.line(c,i,o,u,a1))
for (Case a2 : tab) {
	if(Case.line(y,z,a1,a2,a3) && Case.line(d,j,p,v,a2))
for (Case a4 : tab) {
	if(Case.line(y,z,a1,a2,a3,a4) && Case.line(f,l,r,x,a4,a0))
for (Case a5 : tab) {
	if(Case.line(a,g,m,s,y,a5) && Case.line(a5,a0))
for (Case a6 : tab) {
	if(Case.line(a5,a6,a0) && Case.line(b,h,n,t,z,a6))
for (Case a7 : tab) {
	if(Case.line(a5,a6,a7,a0) && Case.line(c,i,o,u,a1,a7))
for (Case a8 : tab) {
	if(Case.line(a5,a6,a7,a8,a0) && Case.line(d,j,p,v,a2,a8))
for (Case a9 : tab) {
	if(Case.line(a5,a6,a7,a8,a9,a0) && Case.line(e,k,q,w,a3,a9))
if(Case.line(f,k,p,u,z,a5)){
	total++;
solutions.add(Case.afficheAll(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,a1,a2,a3,a4,a5,a6,a7,a8,a9,a0));
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
LinkedList<String> fin = new LinkedList<String>();
for(String x : solutions){
	for(String y : solutions){
		String temp="";
		for(int i=0;i<x.length();i++){
			temp+=""+x.charAt(i)+""+y.charAt(i);
		}
		fin.add(temp);
	}
}
float r=0;
for(String x : fin){
	boolean z=true;
	for(int i=0;i<x.length()-2;i=i+2){
		if(z)
		for(int j=i+2;j<x.length();j=j+2){
			if(x.charAt(i)==x.charAt(j) && x.charAt(i+1)==x.charAt(j+1)){
				z=false;
				r++;
				break;
			}
		}
	}
	if(z){
		System.out.println(x);
	}
}
System.out.println(r);
System.out.println(fin.size());
}
}


