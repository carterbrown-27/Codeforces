#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

template<typename T>
using uset = unordered_set<T>;

#define pb push_back

int dfs(vector<vector<int>> &adj, uset<int> &unvis, int* b, int u){
	unvis.erase(u);
	
	int sum = b[u];
	for(int v: adj[u]){
		if(unvis.find(v) != unvis.end()){
			sum += dfs(adj, unvis, b, v);
		}
	}
	
	return sum;
}

bool solve(){
	int n, m;
	cin >> n >> m;
	
	uset<int> unvis;
	int b[n];
	for(int i = 0; i < n; i++){
		cin >> b[i];
		unvis.insert(i);
	}
	
	vector<vector<int>> adj(n);
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	while(!unvis.empty()){
		int u = *(unvis.begin());
		
		int ans = dfs(adj, unvis, b, u);
		// cout << ans << endl;
		if(ans != 0)
			return false;
	}
	
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	
	cout << (solve() ? "" : "IM") << "POSSIBLE" << endl;
	
	return 0;
}