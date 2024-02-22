#include<iostream>
#include<algorithm>
#include<vector>
#include <string>
using namespace std;
int n, m;
bool check(string s) {
    int mo = 0;
    int ja = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') mo++;
        else ja++;
    }
    if (mo >= 1 && ja >= 2) return true;
    else return false;
}

void go(int start, string s, vector<char> v) {
    if (s.size() == n) {
        if (check(s)) {
            cout<<s<<"\n";
        }
        return;
    }
    if (start == m) {
        return;
    }
    go(start + 1, s+v[start] , v);
    go(start + 1, s,v);
}

int main(void) {

    cin >> n>> m;
    vector<char> v(m);
    for (int i = 0; i < m; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    go(0, "", v);


    return 0;
}
