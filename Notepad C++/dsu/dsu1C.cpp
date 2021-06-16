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
	vector<int> p, s, xp;
	
	DSU(int n): n(n){
		for(int i = 0; i < n; i++)
			p.pb(i);
		s.assign(n, 1);
		xp.assign(n, 0);
	}
	
	int get(int a){
		// treat these as trees (root will point to itself)
		while(a != p[a]){
			// follow path to root, ** No path compression
			a = p[a];
		}
		return a;
	}
	
	void uni(int a, int b){
		a = get(a);
		b = get(b);
		
		if(a == b) return;
		
		// size heuristic
		if(s[a] > s[b]) swap(a,b);
		
		// change pointer of a's root to b's root
		p[a] = b;
		
		// operations (assoc. & commut.)
		s[b] += s[a];
		xp[a] -= xp[b];
	}
	
	void add(int x, int v){
		xp[get(x)] += v;
	}
	
	int getXP(int a){
		int res = xp[a];
		if(a != p[a]){
			res += getXP(p[a]);
		}
		return res;
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
		
		if(op == "join"){
			int x,y;
			cin >> x >> y;
			dsu.uni(x,y);
		}else if(op == "get"){
			int x;
			cin >> x;
			cout << dsu.getXP(x) << endl;
		}else if(op == "add"){
			int x,v;
			cin >> x >> v;
			dsu.add(x,v);
		}
	}
	
	/* for(int i = 1; i <= n; i++){
		cout << dsu.xp[i] << endl;
	} */
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}