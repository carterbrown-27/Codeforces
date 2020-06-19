#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	
	int t[n]{0};
	int first = 0;
	for(char c: s){
		t[c-'a']++;
		first = min(first, c-'a');
	}
	
	int dp[k+1] {0};
	for(int i = 1; i <= k; i++){
		dp[k] = t[first] / i;
	}
	
	for(int i = 1+first; i < 26; i++){
		int tmp = t[i];
		for(int j = k; j >= 1; j--){
			dp[j-1] = max(dp[j-1],min(dp[j-2],tmp/j));
		}
	}
	
	cout << dp[k] << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}