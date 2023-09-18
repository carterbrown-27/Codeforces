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
	int n, k;
	cin >> n >> k;
	
	vector<pair<int,int>> edges;
	vector<vector<int>> prev(k, vector<int>(1,1));
	
	auto add_node = [&] (int i, int c) {
		edges.pb({prev[i].back(), c});
		prev[i].pb(c);
	};
	
	for(int c = 2; c <= n;){
		for(int j = 0; j < k && c <= n; j++){
			add_node(j, c++);
		}
	}
	
	cout << prev[0].size() + prev[1].size() - 2 << endl;
	for(auto &[u,v]: edges){
		cout << u << " " << v << "\n";
		
	}
	cout << std::flush; 
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}