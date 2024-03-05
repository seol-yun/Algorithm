#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include<string>
#include <queue>
#include <cstring>
using namespace std;
int a[51][51];
int dist[51][51];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int n, m;
vector<pair<int, int>> v;
int minn = -1;
void go(vector<pair<int, int>> vv, int index, int cnt) {
	
	if (cnt == m) {
		memset(dist, -1, sizeof(dist));
		queue<pair<int, int>> q;
		for (int i = 0; i < vv.size(); i++)
		{
			dist[vv[i].first][vv[i].second] = 0;
			q.push({ vv[i].first, vv[i].second });
		}
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
					if (dist[nx][ny] == -1 && a[nx][ny] != 1) {
						dist[nx][ny] = dist[x][y] + 1;
						q.push({ nx, ny });
					}
				}
			}
		}
		int max = 0;
		bool flag = true;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (a[i][j] == 0 && dist[i][j] == -1) flag = false;
				if (a[i][j]==0&&dist[i][j] > max) {
					max = dist[i][j];
				}
			}
		}
		if (flag == true && (max < minn || minn == -1)) {
			minn = max;
		}

	}
	if (index == v.size()) {
		return;
	}
	go(vv, index + 1, cnt);
	vv.push_back({ v[index].first ,v[index].second });
	go(vv, index + 1, cnt + 1);
}
int main() {
    cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 2) {
				v.push_back({ i, j });
			}
		}
	}
	vector<pair<int, int>> q;
	go(q, 0, 0);
	cout << minn;
}
