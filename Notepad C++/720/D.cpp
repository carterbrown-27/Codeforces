#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using uset = unordered_set<T>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

#define pb push_back

void solve() {
	int n;
	cin >> n;
	
	umap<int, set<int>> adj;
	for(int i = 0; i < n-1; i++){
		int a, b;
		cin >> a >> b;
		adj[a].insert(b);
		adj[b].insert(a);
	}
	
	// <deg,u>
	auto comp = []( pair<set<int>*,int> a, pair<set<int>*,int> b ) { return (*(a.first)).size() > (*(b.first)).size(); };
	priority_queue< pair<set<int>*,int> , vector<pair<set<int>*,int>>, decltype( comp ) > mnq( comp );
	
	for(int i = 1; i <= n; i++){
		mnq.push({&(adj[i]), i});
	}
	
	
	int c = 0;
	
	stringstream ss;
	// somethin
	for(int i = 1; i <= n; i++){
		while(adj[i].size() > 2){
			int u = *(adj[i].begin());
			adj[u].erase(i);
			adj[i].erase(u);
			// move an edge
			auto tmp = mnq.top();
			int v = tmp.second;
			adj[u].insert(v);
			adj[v].insert(u);
			
			ss << i << " " << u << " " << u << " " << v << endl;
			c++;
		}
	}
	
	cout << c << endl;
	cout << ss.str() << endl;
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