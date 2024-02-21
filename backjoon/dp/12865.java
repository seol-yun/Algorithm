import java.util.*;


public class Main {
	static int n, k;
	static int[] w = new int[101];
	static int[] v = new int[101];
	static int[][] d = new int[101][100001];
	static int go(int x, int we) {
		if(we>k) return -100001;
		if(d[x][we]!=0) return d[x][we];
		if(we==0) {
			for (int i = x; i < n; i++) {
				d[x][we]=Math.max(d[x][we], go(i, we+w[i])+v[i]);
			}
		}
		else {
			for (int i = x+1; i < n; i++) {
				d[x][we]=Math.max(d[x][we], go(i, we+w[i])+v[i]);
			}
		}
		return d[x][we];
	}
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in); 
		n = scan.nextInt();
		k = scan.nextInt();
		for (int i = 0; i < n; i++) {
			w[i]=scan.nextInt();
			v[i]=scan.nextInt();
		}
		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 100001; j++) {
				d[i][j]=0;
			}
		}
		System.out.println(go(0,0));
	}
}
