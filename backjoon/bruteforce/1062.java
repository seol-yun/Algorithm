import java.util.*;
import java.io.*;

public class Main {
	static int n, k;
	static String a[];
	static boolean word[] = new boolean[26];
	static int ans=0;
	static int calc() {
		int cnt=0;
		for (int i = 0; i < n; i++) {
			int flag=0;
			for (int j = 0; j < a[i].length(); j++) {
				int c = a[i].charAt(j)-'a';
				if(word[c]==false) {
					flag=1;
					break;
				}
			}
			if(flag==0) {
				cnt++;
			}
		}
		return cnt;
	}
	static void go(int idx, int cnt) {
		if(cnt==k) {
			ans=Math.max(ans, calc());
			return;
		}
		for (int i = idx+1; i < 26; i++) {
			if(word[i]==false) {
				word[i]=true;
				go(i, cnt+1);
				word[i]=false;
			}
		}
	}
	public static void main(String args[]) throws IOException{
		Scanner scan = new Scanner(System.in);
		n = scan.nextInt();
		k=scan.nextInt();
		k-=5;
	
		a= new String[n];
		word['a'-'a']=true;
		word['n'-'a']=true;
		word['t'-'a']=true;
		word['i'-'a']=true;
		word['c'-'a']=true;
		for (int i = 0; i < n; i++) {
			a[i]=scan.next();
		}
		if(k<0) {
			System.out.println(0);
			return;
		}
		go(0,0);
		System.out.println(ans);
	}

}
