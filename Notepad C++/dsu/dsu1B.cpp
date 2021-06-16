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

struct DSU {
	int n;
	vector<int> p, s, mn, mx;
	
	DSU(int n): n(n){
		for(int i = 0; i < n; i++)
			p.pb(i);
		s.assign(n, 1);
		mn.assign(p.begin(), p.end());
		mx.assign(p.begin(), p.end());
	}
	
	int get(int a){
		// treat these as trees (root will point to itself)
		if(a != p[a]){
			// follow path to root, update ptr to point to root
			p[a] = get(p[a]);
		}
		return p[a];
	}
	
	void uni(int a, int b){
		a = get(a);
		b = get(b);
		
		if(a == b) return;
		
		// size heuristic
		if(s[a] > s[b]) swap(a,b);
		
		// change pointer of a's root to b's root
		p[a] = b;
		s[b] += s[a];
		mn[b] = min(mn[a], mn[b]);
		mx[b] = max(mx[a], mx[b]);
	}
	
	bool sameSet(int a, int b){
		return get(a) == get(b);
	}
};

void solve() {
	int n, m;
	cin >> n >> m;
	DSU dsu(n+1);
	
	for(int q = 0; q < m; q++){
		string op;
		cin >> op;
		
		if(op == "union"){
			int u,v;
			cin >> u >> v;
			dsu.uni(u,v);
		}else if(op == "get"){
			int v;
			cin >> v;
			int a = dsu.get(v);
			cout << dsu.mn[a] << " " << dsu.mx[a] << " " << dsu.s[a] << endl;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}