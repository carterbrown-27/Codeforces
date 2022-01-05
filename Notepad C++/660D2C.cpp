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

struct ret {
	bool g;
	int s,h;
};

const struct ret BAD = {false,-1,-1};

ret dfs(vector<vector<int>>& adj, int* p, int* h, int u, int par)
{
	int sum = 0, happy = 0;
	for(int v: adj[u]){
		if(v != par){
			// note calling dfs modifies sum & happy
			auto r = dfs(adj, p, h, v, u);
			if(!r.g){
				return BAD;
			}
			sum += r.s;
			happy += r.h;
		}
	}

	sum += p[u];
	
	if(abs(sum % 2) != abs(h[u] % 2)){
		//cout << sum << " !== " << h[u] << endl;
		return BAD;
	}
	
	int cur_h = (sum+h[u])/2;
	if(!(happy <= cur_h && cur_h >= 0 && cur_h <= sum)){
		//cout << happy << " " << cur_h << " " << sum << endl;
		return BAD;
	}
		
	return {true, sum, cur_h};
}

void solve() {
	int n, m;
	cin >> n >> m;
	
	int p[n], h[n];
	
	for(int i = 0; i < n; i++)
		cin >> p[i];
	for(int i = 0; i < n; i++)
		cin >> h[i];
	
	vector<vector<int>> adj(n);
	for(int i = 0; i < n-1; i++){
		int u,v;
		cin >> u >> v;
		u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	cout << (dfs(adj, p, h, 0, -1).g ? "YES" : "NO") << endl;
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