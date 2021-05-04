#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int a,b;
	cin >> a >> b;
	int mn = min(a,b);
	int mx = max(a,b);
	int s = max(2*mn,mx);
	cout << s*s << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}