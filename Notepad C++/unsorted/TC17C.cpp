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

void dfs(int v, int p, int k, vector<vector<int>>& adj, vector<int>& ans)
{	
	int c = 1;
	for(int u: adj[v])
	{	
		if(u == p)
			continue;
		
		while(c == ans[v] || (p != -1 && c == ans[p]))
		{
			c++;
		}
		ans[u] = c++;
		
		dfs(u, v, k, adj, ans);
	}
}

int main() {
	ios::sync_with_stdio(false);
		
	int n;
	cin >> n;
	
	vector<vector<int>> adj(n);
	for(int i = 0; i < n-1; i++)
	{
		int u,v;
		cin >> u >> v;
		u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	int k = 0;
	for(auto vec: adj)
	{
		k = max(k, (int) vec.size());
	}
	k++;
	
	cout << k << endl;
	
	vector<int> ans(n);
	ans[0] = 1;
	dfs(0, -1, k, adj, ans);
	
	for(int x: ans)
		cout << x << " ";
	cout << endl;
	return 0;
}