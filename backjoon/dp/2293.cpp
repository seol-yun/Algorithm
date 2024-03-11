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
	
	d[0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < 10001; j++)
		{
			if (j - a[i] >= 0) {
				d[j] += d[j - a[i]];
			}
			
		}
	}
	cout << d[m];
    return 0;
}
