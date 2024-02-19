import java.util.*;
import java.io.*;
class point {
	int x, y;
	point(int x, int y){
		this.x = x;
		this.y = y;
	}
}
class l implements Comparable<l>{
	int x, y, dist;
	l(int x, int y, int dist){
		this.x = x;
		this.y = y;
		this.dist = dist;
	}
	public int compareTo(l o) {
		if(dist<o.dist) {
			return -1;
		}
		else if(dist==o.dist) {
			if(x<o.x) {
				return -1;
			}
			else if(x==o.x) {
				if(y<o.y) {
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
		else {
			return 1;
		}
	}
}
public class Main {
	static int n;
	static int a[][];
	static int d[][];
	static int dx[] = {-1,0,0,1};
	static int dy[] = {0,-1,1,0};
	static int ans=0;
	static point bfs(int sx, int sy, int size){
		Queue<point> q = new LinkedList<>();
		ArrayList<l> arr = new ArrayList<>();
		d[sx][sy]=0;
		q.add(new point(sx, sy));
		while(!q.isEmpty()) {
			int x = q.peek().x;
			int y = q.peek().y;
			q.poll();
			for (int i = 0; i < 4; i++) {
				int nx = x+dx[i];
				int ny = y+dy[i];
				if(0<=nx&&nx<n&&0<=ny&&ny<n) {
					if(d[nx][ny]==-1&&a[nx][ny]<=size) {
						if(a[nx][ny]!=0&&a[nx][ny]<size) {
							
							arr.add(new l(nx, ny, d[x][y]+1));
						}
						d[nx][ny]=d[x][y]+1;
						q.add(new point(nx, ny));

					}
				}
			}
		}
		if(arr.isEmpty()) {
			return new point(-1, -1);
		}
		else {
			Collections.sort(arr);
			ans+=arr.get(0).dist;
			a[arr.get(0).x][arr.get(0).y]=0;
			return new point(arr.get(0).x, arr.get(0).y);
		}
	}
	public static void main(String args[]) throws IOException{
		Scanner scan = new Scanner(System.in);
		n = scan.nextInt();
		a = new int[n][n];
		d= new int[n][n];
		int x=0, y=0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j]=scan.nextInt();
				if(a[i][j]==9) {
					a[i][j]=0;
					x=i;
					y=j;
				}
			}
		}
		int cnt=0;
		int size=2;
		while(true) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					d[i][j]=-1;
				}
			}
			point t=bfs(x, y, size);
			x=t.x;
			y=t.y;
			if(x==-1&&y==-1) {
				System.out.println(ans);
				return;
			}
			cnt++;
			if(cnt==size) {
				size++;
				cnt=0;
			}

		}

	}

}
