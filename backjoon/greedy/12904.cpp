#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdio>
#include<tuple>
using namespace std;
string n, m;

void go(string ss) {
	if (ss == n) {
		cout << 1;
		return;
	}
	else if (ss.size() <= n.size()) {
		cout << 0;
		return;
	}
	if (ss[ss.size() - 1] == 'A') {
		string s;
		for (int i = 0; i < ss.size() - 1; i++)
		{
			s += ss[i];
		}
		go(s);
	}
	if (ss[ss.size() - 1] == 'B') {
		string s;
		for (int i = ss.size() - 2; i >= 0; i--)
		{
			s += ss[i];
		}
		go(s);
	}
}

int main() {
	cin >> n >> m;
	go(m);
	return 0;
}
