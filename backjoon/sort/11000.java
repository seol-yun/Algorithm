import java.util.*;
class point implements Comparable<point>{
	int start, end;
	point(int start, int end){
		this.start=start;
		this.end=end;
	}
	public int compareTo(point that) {
		if(this.start<that.start) {
			return -1;
		}
		else if(this.start==that.start) {
			if(this.end<that.end) {
				return -1;
				
			}
			else if(this.end>that.end) {
				return 1;
			}
			else {
				return 0;
			}
		}
		else {
			return 1;
		}
	}
}

public class Main {
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		point[] a =new point[n];
		PriorityQueue<Integer> q = new PriorityQueue<Integer>();
		for (int i = 0; i < n; i++) {
			int x=scan.nextInt();
			int y = scan.nextInt();
			a[i]=new point(x, y);
		}
		Arrays.sort(a);
		q.add(a[0].end);
		for (int i = 1; i < n; i++) {
			int x = q.peek();
			if(x<=a[i].start) {
				q.poll();
				q.add(a[i].end);
			}
			else {
				q.add(a[i].end);
			}
		}
		System.out.println(q.size());
	}
}
