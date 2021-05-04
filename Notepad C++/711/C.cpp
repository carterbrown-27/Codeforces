#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

#define pb push_back

const int MOD = 1e9+7;
// pos, k, l/r
ll dp[1000][1000][2];

ll dfs(int pos, int n, int k, int dir){
	if(pos<0 || pos>=n) return k>0;
	
	if(dp[pos][k][dir] != 0){
		return dp[pos][k][dir];
	}
	
	if(k <= 1){
		return dp[pos][k][dir] = 1;
	} 
	
	int d = (dir ? 1 : -1);
	
	ll reb = dfs(pos-d, n, k-1, 1-dir);
	ll cont = dfs(pos+d, n, k, dir);
	
	
	return dp[pos][k][dir] = ((cont + reb) % MOD);
}

void solve() {
	int n,k;
	cin >> n >> k;
	memset(dp, 0, sizeof dp);
	ll ans = dfs(0,n,k,true);
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}