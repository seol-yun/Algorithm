#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdio>
#include<tuple>
#include <set>
using namespace std;
int n;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	cin >> n;
	vector<int> vp;
	vector<int> vm;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		if (k > 0) {
			vp.push_back(k);
		}
		else {
			vm.push_back(k);
		}
	}
	sort(vp.begin(), vp.end(), cmp);
	sort(vm.begin(), vm.end());
	int ans = 0;
	if (vp.size() > 1) {
		for (int i = 0; i < vp.size() - 1; i += 2)
		{
			if (vp[i] + vp[i + 1] < vp[i] * vp[i + 1]) {
				ans += vp[i] * vp[i + 1];
			}
			else {
				ans += vp[i] + vp[i + 1];
			}
		}
	}
	
	if (vp.size() % 2 == 1) {
		ans+=vp[vp.size()-1];
	}
	if (vm.size() > 1) {
		for (int i = 0; i < vm.size() - 1; i += 2)
		{
			ans += vm[i] * vm[i + 1];
		}
	}
	
	if (vm.size() % 2 == 1) {
		ans += vm[vm.size()-1];
	}
	cout << ans;
}
