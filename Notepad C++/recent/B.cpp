#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int n;
	cin >> n;
	int s[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &s[i]);
	}
	
	sort(s, s+n);
	int mn = 1e8;
	for(int i = 1; i < n; i++){
		mn = min(s[i] - s[i-1],mn);
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