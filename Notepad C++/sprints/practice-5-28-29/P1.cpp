#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int n;
	cin >> n;
	int s[n+1];
	for(int i = 1; i <= n; i++){
		scanf("%d", &s[i]);
	}
	
	int dp[n+1];
	for(int i = 1; i <= n; i++){
		dp[i] = 1;
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = i+i; j <= n; j+=i){
			if(s[j] > s[i]){
				dp[j] = max(dp[j],dp[i]+1);
			}
		}
	}
	
	int mx = 0;
	for(int i = 1; i <= n; i++){
		mx = max(mx, dp[i]);
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