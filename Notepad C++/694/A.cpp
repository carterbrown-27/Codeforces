#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int n, x;
	cin >> n >> x;
	ll sum = 0;
	ll mxb = 0;
	for(int i = 0; i < n; i++){
		int v;
		cin >> v;
		sum += v;
		mxb += v/x + (v % x > 0);
	}
	
	cout << sum / x + (sum % x > 0) << " " << mxb << "\n";
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}