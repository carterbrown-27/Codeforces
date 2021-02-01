#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

// for each city, best end spot with/without move 2.
int dp[200001][2];

int find(vector<vector<int>> &g, vector<int> &d, set<int> &path, int u, bool used){
	if(dp[u][used] != -1){
		return dp[u][used];
	}
	// cout << u << " " <<  used << endl;
	
	path.insert(u);
	
	int mn = d[u];
	for(int v: g[u]){
		if(path.find(v) != path.end()) continue;
		if(!used && d[u] >= d[v]){
			mn = min(mn, find(g, d, path, v, true));
		}
		if(d[u] < d[v]){
			mn = min(mn, find(g, d, path, v, false));
		}
	}
	
	path.erase(u);
	dp[u][used] = mn;
	if(!used) dp[u][true] = mn;
	return mn;
}

void solve() {
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> g(n);
	
	for(int i = 0; i < m; i++){
		int u,v;
		cin >> u >> v;
		g[u-1].pb(v-1);
	}
	
	vector<int> d(n, -1);
	// flood fill
	d[0] = 0;
	vector<int> prev;
	prev.pb(0);
	int dist = 0;
	while(!prev.empty()){
		vector<int> tmp;
		for(int u: prev){
			for(int v: g[u]){
				if(d[v] == -1) tmp.pb(v);
			}
			d[u] = dist;
		}
		dist++;
		prev = tmp;
	}
	
	/*
	for(int i = 0; i < n; i++){
		cout << d[i] << " ";
	}
	cout << endl;
	*/
	
	memset(dp, -1, sizeof(dp));
	dp[0][false] = dp[0][true] = 0;
	for(int i = 0; i < n; i++){
		set<int> path;
		int ans = find(g, d,path, i, false);
		cout << ans << " ";
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}