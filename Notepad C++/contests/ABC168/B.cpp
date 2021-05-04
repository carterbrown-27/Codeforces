#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	string s;
	int k;
	cin >> k;
	cin >> s;
	cout << s.substr(0,k) << (s.length() > k ? "..." : "") << endl;
}

int main() {
	solve();
	return 0;
}