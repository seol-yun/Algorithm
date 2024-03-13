#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdio>
#include<tuple>

using namespace std;
int n, k;

int main() {
	cin >> n>>k;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<int> b(n-1);
	for (int i = 0; i < n-1; i++)
	{
		b[i] = a[i + 1] - a[i];
	}
	sort(b.begin(), b.end());
	int sum = 0;
	for (int i = 0; i < n-k; i++)
	{
		sum += b[i];
	}
	cout << sum;
	return 0;
}
