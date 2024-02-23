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
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (sum + 1 < a[i]) {
			break;
		}
		sum += a[i];
	}
	cout << sum+1;
	return 0;
}
