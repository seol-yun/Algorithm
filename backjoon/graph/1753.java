import java.util.*;
import java.io.*;
class point implements Comparable<point>{
	int x, y;
	point(int x, int y){
		this.x =x;
		this.y=y;
	}
	@Override
	public int compareTo(point o) {
		// TODO Auto-generated method stub
		if(y<o.y) {
			return -1;
		}
		else if(y==o.y) {
			if(x<o.x) {
				return -1;
			}
			else {
				return 1;
			}
		}
		else {
			return 1;
		}
		
	}
}
public class Main {
	static int n, m, k;
	static boolean check[] = new boolean[20001];
	static int d[] = new int[20001];
	public static void main(String args[]) throws IOException{
		Scanner scan = new Scanner(System.in);
		n=scan.nextInt();
		m=scan.nextInt();
		k=scan.nextInt();
		List<point> [] a = new List[n+1];
		for (int i = 1; i <= n; i++) {
			a[i]= new ArrayList<>();
			d[i]=200000;
		}
		for (int i = 0; i < m; i++) {
			int x = scan.nextInt();
			int y = scan.nextInt();
			int c = scan.nextInt();
			a[x].add(new point(y, c));
		}
		PriorityQueue<point> q =new PriorityQueue<>();
		q.add(new point(k, 0));
		d[k]=0;
		while(!q.isEmpty()) {
			int x = q.peek().x;
			q.poll();
			if(check[x]==true) continue;
			check[x]=true;
			for (int i = 0; i < a[x].size();i++) {
				int nx = a[x].get(i).x;
				int nc = a[x].get(i).y;
				if(d[nx]>d[x]+nc) {
					d[nx]=d[x]+nc;
					q.add(new point(nx, d[nx]));
				}
			}
		}
		for (int i = 1; i <=n ; i++) {
			if(d[i]==200000) System.out.println("INF");
			else System.out.println(d[i]);
		}
	}

}
