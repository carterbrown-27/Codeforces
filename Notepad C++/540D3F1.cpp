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

// returns # of nice edges
int dfs(int v, int p, int& r, int& b, const int tr, const int tb, const vector<vector<int>>& adj, const int* a)
{
	int res = 0;
	int cr = 0, cb = 0;
	for(int u: adj[v]){
		if(u != p)
			res += dfs(u, v, cr, cb, tr, tb, adj, a);
	}
	
	if(a[v] == 1){
		cr++;
	}else if(a[v] == 2){
		cb++;
	}
	
	// cur edge
	// cout << p << " " << v << endl;
	// subcmp is nice, parcmp is nice
	if((cb == 0 || cr == 0) && (tb-cb == 0 || tr-cr == 0))
		res++;
	
	r += cr;
	b += cb;
	
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	// 1=r, 2=b
	vector<int> cnt(3);
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		++cnt[a[i]];
	}
	
	vector<vector<int>> adj(n);
	for(int i = 0; i < n-1; i++){
		int u,v;
		cin >> u >> v;
		u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	int tmpr = 0, tmpb = 0;
	cout << dfs(0, -1, tmpr, tmpb, cnt[1], cnt[2], adj, a) << endl;
	return 0;
}