#include<iostream>
#include<string>
#include<stdlib.h>
#include <algorithm>
#include<queue>
#include <cstring>
#include <map>
using namespace std;
int n, m;
int a[2001];
int d[2001][2001];

int go(int s, int e) {
	if (s >= e) return 2;
	if (d[s][e] != 0) return d[s][e];
	if (a[s] == a[e]) {
		return d[s][e]=go(s + 1, e - 1);
	}
	else {
		return d[s][e]=1;
	}
	
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int s, e;
		scanf("%d %d", &s, &e);
		printf("%d\n",go(s, e)-1);

	}
	return 0;
}
