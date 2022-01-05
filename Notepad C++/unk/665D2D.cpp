#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct point {
	int x,y;
};

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

template<typename T>
using uset = unordered_set<T>;

#define pb push_back

const int MOD = 1e9+7;

// return = # of nodes in subgraph
int dfs(int u, int p, vector<ll>& edges, vector<vector<int>>& adj){
	int sum = 1;
	for(int v: adj[u]){
		if(v != p){
			int res = dfs(v, u, edges, adj);
			sum += res;
			edges.pb(1LL*res*(adj.size()-res));
			//cout << v << " " << res << endl;
		}
	}
	
	return sum;
}

void solve() {
	int n;
	cin >> n;
	
	vector<vector<int>> adj(n);
	for(int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	int m;
	cin >> m;
	
	vector<ll> labels(m);
	for(auto &l: labels)
		cin >> l;
	
	for(int i = 0; i < n-1-m; i++)
		labels.pb(1);
	
	sort(labels.begin(), labels.end());
	
	for(int i = m-1; i >= n-1; i--){
		labels[n-2] = (labels[n-2]*labels[i])%MOD;
		//cout << labels[i] << " ";
		// labels.pop_back();
	}
	//cout << labels[n-2] << endl;;
	
	vector<ll> edges;
	dfs(0, -1, edges, adj);
	
	sort(edges.begin(), edges.end());
	
	// use biggest weights on most travelled
	ll ans = 0;
	for(int i = 0; i < n-1; i++){
		ans = (ans + (edges[i]*labels[i])% MOD) % MOD;
	}
	
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