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

pair<int,bool> dfs(int u, int p, vector<vector<int>>& adj, vector<int>& buds)
{
	int leaves = 0;
	if(u != 0 && adj[u].size() == 1){
		return {1, true};
	}
	
	bool isBud = true;
	for(int v: adj[u]){
		if(v != p){
			auto res = dfs(v, u, adj, buds);
			leaves += res.first;
			if(!res.second)
				isBud = false;
		}
	}
	
	// cout << u << " " << isBud << endl;
	
	if(u != 0 && isBud){
		buds.pb(u);
	}
	return {leaves, false};
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
	
	vector<int> buds;
	int leaves = dfs(0, -1, adj, buds).first;
	
	int budSum = 0;
	int mx = 0;
	//cout << endl;
	for(int b: buds){
		//cout << b << " ";
		int l = adj[b].size()-1;
		budSum += l;
		mx = max(mx, l);
	}
	//cout << endl;
	int ans = leaves - (int) buds.size() + (leaves == budSum);
	
	// what if bud movement creates leaves ? :/ 
	
	
	//cout << endl << leaves << " " << budSum << endl;
	cout << max(mx, ans) << endl;
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