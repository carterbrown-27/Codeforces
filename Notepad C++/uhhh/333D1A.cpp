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
	
	vector<uset<int>> rails(n);
	for(int i = 0; i < m; i++){
		int u,v;
		cin >> u >> v;
		u--, v--;
		rails[u].insert(v);
		rails[v].insert(u);
	}
	
	auto& adj = rails;
	vector<uset<int>> roads(n);
	// direct 1->n path is in rails
	if(rails[0].find(n-1) != rails[0].end()){
		// need to flip our adj
		for(int i = 0; i < n; i++){
			for(int j = 0; j < i; j++){
				if(rails[i].find(j) == rails[i].end()){
					roads[i].insert(j);
					roads[j].insert(i);
				}
			}
		}
		adj = roads;
	}
	
	// simple bfs
	const int INF = 1e6;
	queue<int> q;
	q.push(0);
	vector<int> d(n, INF);
	d[0] = 0;
	
	while(!q.empty()){
		int u = q.front();
		q.pop();
		
		for(int v: adj[u]){
			if(d[v] == INF){
				d[v] = d[u]+1;
				q.push(v);
			}
		}
	}
	
	cout << (d[n-1] == INF ? -1 : d[n-1]) << endl;
	return 0;
}