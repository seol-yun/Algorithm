#include<iostream>
#include<string>
#include<stdlib.h>
#include <algorithm>
#include<queue>
#include <cstring>
#include <map>
using namespace std;
int n, m;
int a[501][501];
int d[501][501];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int dfs(int x, int y) {
	if (x == n - 1 && y == m - 1) {
		return 1;
	}
	if (d[x][y] != -1) return d[x][y];
	d[x][y] = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < m) {
			if (a[nx][ny] < a[x][y]) {
				d[x][y]+=dfs(nx, ny);
			}
		}
	}
	return d[x][y];
}

int main() {
	cin >> n>>m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	memset(d, -1, sizeof(d));
	cout<<dfs(0, 0);
	
	return 0;
}
