#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include<stack>
#include<queue>
#include<string>
using namespace std;
int n, k;
long long d[201][201];
long long mod = 1000000000;
;int main() {
	cin >> n >> k;
	for (int i = 0; i <= k; i++)
	{
		d[0][i] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <=k ; j++)
		{
			for (int t = 0; t <=i ; t++)
			{
				d[i][j] += d[i - t][j - 1]%mod;
			}

		}
	}
	cout << d[n][k]%mod;
	return 0;
}
