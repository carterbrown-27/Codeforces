#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using uset = unordered_set<T>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

#define pb push_back

void dfs(vector<vector<int>>& adj, bool* col, bool* vis, int v, bool c){
	if(vis[v]) return;
	vis[v] = true;
	col[v] = c;
	for(int u: adj[v]){
		dfs(adj, col, vis, u, !c);
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> adj(n);
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	bool col[n], vis[n];
	memset(col, 0, sizeof col);
	memset(vis, 0, sizeof vis);
	dfs(adj, col, vis, 0, false);
	
	int c = 0;
	for(int i = 0; i < n; i++)
		c += col[i];
	
	bool b = (c <= n/2);
	
	cout << (b ? c : n-c) << endl;
	for(int i = 0; i < n; i++)
		if(col[i] == b)
			cout << i+1 << " ";
	
	cout << endl;
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