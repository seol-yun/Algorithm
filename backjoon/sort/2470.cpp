#include <iostream>
#include <cmath>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	vector<int> a;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		a.push_back(k);
	}
	sort(a.begin(), a.end());
	
	int r = n - 1;
	int l = 0;
	int little = a[0];
	int large = a[n - 1];
	int s = abs(a[0]+a[n-1]);
	while (true) {
		if (r <= l) {
			break;
		}
		int sum = a[r] + a[l];
		if (abs(sum) < s) {
			little = a[l];
			large = a[r];
			s = abs(sum);
		}
		if (sum > 0) {
			r -= 1;
		}
		else if (sum < 0) {
			l += 1;
		}
		else break;
	}
	cout << little << " " << large;
	return 0;

}
