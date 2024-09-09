#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdio>
#include<tuple>
#include <stack>
using namespace std;
int n, c;
int a[200001];

bool go(int mid) {
	int small = a[0];
	int cnt = 1;
	for (int i = 1; i < n; i++)
	{
		if (a[i] - small >= mid) {
			cnt++;
			small = a[i];
		}
	}
	if (cnt >= c) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n>> c;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	int left = 0;
	int right = a[n - 1];
	int ans=0;
	while (left<=right)
	{
		int mid = (left + right) / 2;
		if (go(mid)) {
			
			left = mid + 1;
			if (ans < mid) {
				ans = mid;
			}	
		}
		else {
			right = mid - 1;
		}
	}
	cout << ans;
	return 0;
}
