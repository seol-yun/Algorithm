#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int a[501][501];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	int m;
	cin >> m;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int temp=0;
			if (j + 3 < m&&i<n) {
				temp = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i][j + 3];
				if (ans < temp) {
					ans = temp;
				}
			}
			if (i + 3 < n&&j<m) {
				temp = a[i][j] + a[i+1][j] + a[i+2][j] + a[i+3][j];
				if (ans < temp) {
					ans = temp;
				}
			}
			if (i + 1 < n && j + 1 < m) {
				temp = a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1];
				if (ans < temp) {
					ans = temp;
				}
			}
			if (i + 2 < n && j + 1 < m) {
				temp = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i][j + 1];
				if (ans < temp) {
					ans = temp;
				}
			}
			if (i + 1 < n && j + 2 < m) {
				int temp = a[i][j] + a[i+1][j] + a[i + 1][j + 1] + a[i + 1][j + 2];
				if (ans < temp) ans = temp;
			}
			if (i + 1 < n && j + 2 < m) {
				int temp = a[i][j] + a[i+1][j] + a[i][j + 1] + a[i][j + 2];
				if (ans < temp) ans = temp;
			}
			if (i + 1 < n && j + 2 < m) {
				int temp = a[i+1][j] + a[i+1][j + 1] + a[i+1][j + 2] + a[i][j + 2];
				if (ans < temp) ans = temp;
			}
			if (i + 1 < n && j + 2 < m) {
				int temp = a[i][j] + a[i][j + 1] + a[i ][j + 2] + a[i + 1][j + 2];
				if (ans < temp) ans = temp;
			}
			if (i + 2 < n && j + 1 < m) {
				int temp = a[i][j] + a[i][j + 1] + a[i + 1][j + 1] + a[i + 2][j + 1];
				if (ans < temp) ans = temp;
			}
			if (i + 2 < n && j + 1 < m) {
				int temp = a[i+1][j] + a[i+2][j] + a[i + 1][j + 1] + a[i][j + 1];
				if (ans < temp) ans = temp;
			}
			if (i + 2 < n && j + 1 < m) {
				int temp = a[i][j] + a[i+1][j] + a[i + 1][j + 1] + a[i + 2][j + 1];
				if (ans < temp) ans = temp;
			}
			if (i + 1 < n && j + 2 < m) {
				int temp = a[i][j] + a[i][j + 1] + a[i + 1][j + 1] + a[i + 1][j + 2];
				if (ans < temp) ans = temp;
			}
			if (i + 1 < n && j + 2 < m) {
				int temp = a[i+1][j] + a[i+1][j + 1] + a[i][j + 1] + a[i][j + 2];
				if (ans < temp) ans = temp;
			}
			if (i + 2 < n && j + 1 < m) {
				int temp = a[i][j] + a[i+1][j] + a[i + 2][j] + a[i + 2][j + 1];
				if (ans < temp) ans = temp;
			}
			if (i + 2 < n && j + 1 < m) {
				int temp = a[i+2][j] + a[i+2][j + 1] + a[i + 1][j + 1] + a[i][j + 1];
				if (ans < temp) ans = temp;
			}
			if (i + 1 < n && j + 2 < m) {
				int temp = a[i+1][j] + a[i+1][j + 1] + a[i][j + 1] + a[i+1][j + 2];
				if (ans < temp) ans = temp;
			}
			if (i + 1 < n && j + 2 < m) {
				int temp = a[i][j] + a[i][j + 1] + a[i + 1][j + 1] + a[i][j + 2];
				if (ans < temp) ans = temp;
			}
			if (i + 2 < n && j + 1 < m) {
				int temp = a[i][j] + a[i+1][j] + a[i + 1][j + 1] + a[i + 2][j];
				if (ans < temp) ans = temp;
			}
			if (i + 2 < n && j + 1 < m) {
				int temp = a[i+1][j] + a[i][j + 1] + a[i + 1][j + 1] + a[i + 2][j + 1];
				if (ans < temp) ans = temp;
			}
		}	 
	}
	cout << ans;
	return 0;
}
