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
	
	int n;
	cin >> n;
	
	vector<vector<int>> adj(n);
	int e = n-1;
	for(int i = 0; i < e; i++){
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	// find leaves
	uset<int> leaves;
	for(int i = 0; i < n; i++)
		if(adj[i].size() == 1)
			leaves.insert(i);
	
	int root = *(leaves.begin());
	
	// minimum
	queue<int> q;
	q.push(root);
	
	int dist[n];
	for(int i = 0; i < n; i++)
		dist[i] = -1;
	dist[root] = 0;
	
	while(!q.empty()){
		int u = q.front();
		for(int v: adj[u]){
			if(dist[v] == -1){
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
		q.pop();
	}
	
	bool works = true;
	for(int l: leaves){
		if(dist[l]%2 != 0){
			works = false;
			break;
		}
	}
	
	int mn = (works ? 1 : 3);
	
	// maximum
	int mx = e;
	for(int u = 0; u < n; u++){
		int c = 0;
		for(int v: adj[u]){
			if(leaves.find(v) != leaves.end())
				c++;
		}
		if(c>1)
			mx -= c-1;
	}
	
	cout << mn << " " << mx << endl;
	return 0;
}