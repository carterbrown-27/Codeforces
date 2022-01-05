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

pair<ll,int> dfs(const uset<int>& unis, vector<vector<int>>& adj, int u, int from)
{
	ll sum = 0;
	int uniCount = 0;
	for(int v: adj[u]){
		if(v != from){
			auto p = dfs(unis, adj, v, u);
			// sum of subtree + weight of edge connecting it
			sum += p.first + min(p.second, (int) unis.size() - p.second);
			uniCount += p.second;
		}
	}
	
	if(unis.find(u) != unis.end())
		uniCount++;
	
	return {sum, uniCount};
}

int main() {
	ios::sync_with_stdio(false);
	
	int n, k;
	cin >> n >> k;
	
	uset<int> unis;
	for(int i = 0; i < 2*k; i++){
		int v;
		cin >> v;
		unis.insert(v-1);
	}
	
	vector<vector<int>> adj(n);
	for(int i = 0; i < n-1; i++){
		int u,v;
		cin >> u >> v;
		u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	// root about a university
	int root = *(unis.begin());
	// sum of edges
	auto ans = dfs(unis, adj, root, -1);
	cout << ans.first << endl;
	return 0;
}