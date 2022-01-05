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

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	
	const int MAX = 1e8;
	int minc = MAX;
	vector<vector<pair<int,int>>> adj(n);
	for(int i = 0; i < m; i++){
		int u, v, s;
		cin >> u >> v >> s;
		u--, v--;

		minc = min(minc, abs(k-s));
		
		int w = max(s-k, 0);
		adj[u].pb({w,v});
		adj[v].pb({w,u});
	}
	
	bool connected = true;
	{
		queue<int> q;
		vector<bool> vis(n, false);
		q.push(0);
	
		while(!q.empty()){
			int u = q.front();
			q.pop();
			
			if(vis[u])
				continue;
			
			vis[u] = true;
			
			for(auto &e: adj[u])
				if(e.first == 0 && !vis[e.second])
					q.push(e.second);
		}
	
		for(bool b: vis){
			if(!b){
				connected = false;
				break;
			}
		}
	}
	
	// Prim's
	int cost = 0;	
	{
		minpq<pair<int,int>> pq;
		vector<bool> vis(n,false);
		vector<int> key(n, MAX);

		if(connected){
			cout << minc << endl;
			return;
		}else{
			pq.push({0,0});
			key[0] = 0;
		}
		
		while(!pq.empty()){
			auto p = pq.top();
			
			int u = p.second;
			pq.pop();
			
			if(vis[u])
				continue;
			
			vis[u] = true;
			cost += p.first;
			
			for(auto &e: adj[u]){
				int v = e.second;
				if(!vis[v] && e.first < key[v]){
					pq.push(e);
					key[v] = e.first;
				}
			}
		}
	}
	
	
	cout << cost << endl;
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