#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdio>
#include<tuple>
#include <set>
using namespace std;
int n;

int main() {
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		q.push(k);
	}
	int ans = 0;
	while (q.size()>1)
	{
		int t1 = q.top();
		q.pop();
		int t2 = q.top();
		q.pop();
		ans += t1 + t2;
		q.push(t1 + t2);
	}
	cout << ans;
	return 0;
}
