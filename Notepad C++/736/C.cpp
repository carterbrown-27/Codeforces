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

struct Union {
	vector<set<int>> adj;
	uset<int> safe;
	
	Union(vector<set<int>> &a){
		adj = a;
	}
	
	void init(){
		for(int i = 0; i < adj.size(); i++){
			if(adj[i].upper_bound(i) == adj[i].end()){
				safe.insert(i);
			}
		}
	}
	
	void recalc(int u){
		if(adj[u].upper_bound(u) == adj[u].end()){
			safe.insert(u);
		}else if(safe.find(u) != safe.end()){
			safe.erase(u);
			safe.erase(u);
		}
	}
	
	void recalc(int u, int v){
		recalc(u);
		recalc(v);
	}
	
	void connect(int u, int v, bool b=true){
		adj[u].insert(v);
		adj[v].insert(u);
		if(b) recalc(u,v);
	}
	
	void remove(int u, int v){
		adj[u].erase(v);
		adj[v].erase(u);
		recalc(u,v);
	}
	
	int kill(){
		return safe.size();
	}
};

void solve() {
	int n, m;
	cin >> n >> m;
	
	vector<set<int>> adj(n);
	Union uni(adj);
	
	for(int i = 0; i < m ; i++){
		int u, v;
		cin >> u >> v;
		u--, v--;
		uni.connect(u,v, false);
	}
	
	uni.init();
	
	// TEMP
	/*
	for(int i: uni.safe)
		cout << i << " ";
	cout << endl;
	*/
	int q;
	cin >> q;
	for(int t = 0; t < q; t++){
		int op;
		cin >> op;
		if(op == 3){
			cout << uni.kill() << endl;
		}else{
			int u, v;
			cin >> u >> v;
			u--, v--;
			if(op == 1){
				uni.connect(u,v);
			}else{
				uni.remove(u,v);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}