#include <iostream>
#include <cstring>
#include<vector>
#include<queue>
#include<stack>
#include<deque>
#include <string>
#include<algorithm>
using namespace std;
int n, m;
bool check[101][101];
bool check2[101][101];
char a[101][101];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

void bfs(int sx, int sy, char s) {
	queue<pair<int, int>> q;
	q.push({ sx, sy });
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (check[nx][ny]==false&&a[nx][ny] == s) {
					check[nx][ny] = true;
					q.push({ nx, ny });
				}
			}
		}
	}
	
}
void bfs2(int sx, int sy, char s) {
	queue<pair<int, int>> q;
	q.push({ sx, sy });
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (s == 'R'||s=='G') {
					if (check2[nx][ny] == false&&(a[nx][ny]=='R'|| a[nx][ny] == 'G')) {
						check2[nx][ny] = true;
						q.push({ nx, ny });
					}
				}
				else {
					if (check2[nx][ny] == false && a[nx][ny] == 'B') {
						check2[nx][ny] = true;
						q.push({ nx, ny });
					}
				}
			}
		}
	}

}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int cnt1 = 0;
	int cnt2 = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (check[i][j] == false) {
				bfs(i, j, a[i][j]);
				cnt1++;
			}
			if (check2[i][j] == false) {
				bfs2(i, j, a[i][j]);
				cnt2++;
			}
		}
	}

	cout << cnt1 << " " << cnt2;
	return 0;
}
