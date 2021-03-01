#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int n;
	cin >> n;
	
	int a[n], b[n], c[n];
	for(int i = 0; i < n; i++){
		cin >> c[i];
		c[i]--;
	} 
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i]--;
	} 
	for(int i = 0; i < n; i++){
		cin >> b[i];
		b[i]--;
	}
	
	ll dp[n];
	dp[0] = 0;
	ll mx = 0;
	for(int i = 1; i < n; i++){
		// converge case
		if(a[i] == b[i]){
			dp[i] = 0;
		
		// if prev!=first, go to top/bottom if best
		}else{
			int lower = max(a[i], b[i]);
			int higher = min(a[i], b[i]);
			ll prev = i > 1 ? (dp[i-1] + (c[i-1]-lower) + higher) : 0;
			dp[i] = max(prev, 1LL*lower-higher);
		}
		
		// chain-connecting edges
		dp[i] += 2;
		
		// if end here
		mx = max(mx, dp[i] + c[i]);
	}
	
	cout << mx << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}