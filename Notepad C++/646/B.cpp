#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	string s;
	cin >> s;
	
	int n = s.length();
	int ones[n+1];
	ones[0] = 0;
	for(int i = 1; i <= n; i++){
		ones[i] = ones[i-1] + (s[i-1] - '0');
	}
	
	int mn = 1e5;
	for(int i = 0; i <= n; i++){
		int lo = ones[i];
		int lz = i-lo;
		int ro = ones[n] - ones[i];
		int rz = (n-i)-ro;
		
		mn = min(mn, min(lo,lz) + min(ro,rz));
	}
	
	cout << mn << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}