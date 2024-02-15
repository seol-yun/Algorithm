#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdio>
#include<tuple>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first;
		v[i].second = i;
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i].second - i> ans) {
			ans = v[i].second - i;
		}
	}
	cout << ans+1;
	
	return 0;
}
