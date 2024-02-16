#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include<string>
#include <queue>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n, m;
vector<int> a[32001];
int ind[32001];
int main() {
	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		ind[y]++;
	}
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (ind[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		cout << t << " ";
		for (int i = 0; i < a[t].size(); i++)
		{
			ind[a[t][i]] -= 1;
			if (ind[a[t][i]] == 0) {
				q.push(a[t][i]);
			}
		}
	}
	return 0;
}
