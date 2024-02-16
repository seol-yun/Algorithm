#include<iostream>
#include<string>
#include<stdlib.h>
#include <algorithm>
#include<queue>
#include <cstring>
using namespace std;
int d[51];
int a[9][9];
bool check[9][9];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int n, m;
void bfs(int startx, int starty) {
	queue<pair<int, int>> q;
	q.push(make_pair(startx, starty));
	check[startx][starty] = true;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (check[nx][ny] == false && a[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					check[nx][ny] = true;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	int max = 0;
	
	for (int u = 0; u < n; u++)
	{
		for (int v = 0; v < m; v++)
		{
			if (a[u][v] != 0) continue;
			for (int x = 0; x < n; x++)
			{
				for (int y = 0; y < m; y++)
				{
					if (a[x][y] != 0) continue;
					for (int q = 0; q < n; q++)
					{
						for (int p = 0; p < m; p++)
						{
							if (a[q][p] != 0) continue;
							if (u == x && v == y) continue;
							if (u == q && v == p) continue;
							if (q == x && p == y) continue;
							a[u][v] = 1;
							a[x][y] = 1;
							a[q][p] = 1;
						
							memset(check, false, sizeof(check));
							for (int i = 0; i < n; i++)
							{
								for (int j = 0; j < m; j++)
								{
									if (a[i][j] == 2 && check[i][j] == false) {
										bfs(i, j);
									}
								}
							}
							int sum = 0;
							for (int i = 0; i < n; i++)
							{
								for (int j = 0; j < m; j++)
								{
									if (a[i][j] == 0 && check[i][j] == false) {
										sum++;
									}
								}
							}
							if (sum > max) {
								max = sum;
							}
							a[u][v] = 0;
							a[x][y] = 0;
							a[q][p] = 0;
						}
					}
				}
			}
		}
	}
	cout << max;
	return 0;
}
