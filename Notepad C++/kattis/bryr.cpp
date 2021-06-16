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

int main() {
	ios::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<pair<int,int>>> edges(n);
	
	for(int i = 0; i < m; i++){
		int u, v, c;
		cin >> u >> v >> c;
		u--, v--;
		edges[u].pb({v,c});
		edges[v].pb({u,c});
	}
	
	// dijkstra's w/ pq
	
	const int MXV = 1e9;
	
	vector<int> dist(n, MXV);
	dist[0] = 0;
	
	set<pair<int,int>> q;
	for(int i = 0; i < n; i++)
		q.insert({dist[i], i});
	
	while(!q.empty()){
		auto t = q.begin();
		int u = t->second;
		q.erase(t);
		
		for(auto p: edges[u]){
			int v = p.first;
			
			if(dist[u] + p.second < dist[v]){
				q.erase(q.find({dist[v], v}));
				dist[v] = dist[u] + p.second;
				q.insert({dist[v], v});
			}
		}
	}
	
	cout << dist[n-1] << endl;
	
	return 0;
}