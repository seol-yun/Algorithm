#include<iostream>
#include<string>
#include<stdlib.h>
#include <algorithm>
#include<queue>
#include <cstring>
#include <map>
using namespace std;
int n, m;
int a[101];
int d[10001];

int main() {
	cin >> n>>m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	memset(d, -1, sizeof(d));
	d[0] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < 10001; j++)
		{
			if (j - a[i] >= 0&& d[j - a[i]]!=-1) {
				if (d[j] == -1) {
					d[j] = d[j - a[i]] + 1;
				}
				d[j] = min(d[j],d[j - a[i]]+1);
			}
			
		}
	}
	if (d[m] == -1) cout << -1;
	else cout << d[m];
    return 0;
}
