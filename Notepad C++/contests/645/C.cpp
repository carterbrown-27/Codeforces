#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

ll sigma(ll n){
	return n*(n+1)/2;
}

void solve() {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	
	int dx = x2-x1;
	int dy = y2-y1;
	
	cout << (1ll*dx*dy)+1 << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}