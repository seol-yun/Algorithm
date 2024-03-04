#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
int n, m;
char a[26][26];
int dx[] = { 1, -1, 0,0 };
int dy[] = { 0, 0, 1, -1 };
int dist[26][26];
int max1 = 0;

void dfs(vector<bool> &board, int x, int y, int cnt) {
	
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (board[a[nx][ny]-'A']==false&&dist[nx][ny] == 0) {
					board[a[nx][ny] - 'A'] = true;
					dist[nx][ny] = 1;
					dfs(board, nx, ny, cnt + 1);
					board[a[nx][ny] - 'A'] =false;
					dist[nx][ny] = 0;
				}
			
			
		}
	}
	if (cnt > max1) {
		max1 = cnt;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	vector<bool> board(26);
	board[a[0][0] - 'A'] = true;
	dfs(board, 0, 0, 1);
	
	cout << max1;
	return 0;
}
