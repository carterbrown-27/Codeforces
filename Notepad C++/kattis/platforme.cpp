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


struct segtree {
	
	int size;
	vector<ll> sums;
	const ll NONE = -1;
	const ll DV = 0;
	
	ll assoc(ll a, ll b){
		if(b==NONE) return a;
		return b;
	}
	
	void apply(ll& a, ll b){
		a = assoc(a,b);
	}
	
	void init(int n){
		size = 1;
		while(size < n) size*=2;
		sums.assign(2*size, DV);
	}
	
	ll get(int i){
		if(i < 0 || i >= size) return -1;
		return get(i, 0, 0, size);
	}
	
	ll get(int i, int x, int lx, int rx){
		prop(x, lx, rx);
		// if x is a leaf, set it directly
		if(rx-lx == 1){
			return sums[x];
		}
		
		int m = (lx+rx)/2;
		// i is in left
		if(i < m){
			// goto left node
			return get(i, 2*x + 1, lx, m);
		}else{
			// goto right node
			return get(i, 2*x + 2, m, rx);
		}
	}
	
	void prop(int x, int lx, int rx){
		if(rx-lx == 1) return;
		apply(sums[2*x+1], sums[x]);
		apply(sums[2*x+2], sums[x]);
		sums[x] = NONE;
	}
	
	void add(int l, int r, int v){
		return add(l, r, v, 0, 0, size);
	}
	
	void add(int l, int r, int v, int x, int lx, int rx){
		prop(x, lx, rx);
		// segment is completely outside
		if(rx <= l || lx >= r) return;
		
		// segment is completely contained
		if(l <= lx && rx <= r){
			apply(sums[x], v);
			return;
		}
		
		// segment is partially contained (recursive case)
		int m = (lx+rx)/2;
		add(l, r, v, 2*x+1, lx, m);
		add(l, r, v, 2*x+2, m, rx);
	}
};

const int MXC = 100000;

int main() {
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	// y, x1, x2
	vector<vector<int>> plats(n, vector<int>(3));
	for(int i = 0; i < n; i++){
		cin >> plats[i][0] >> plats[i][1] >> plats[i][2];
	}
	
	sort(plats.begin(), plats.end());
	
	// Segtree is overkill for a problem with these constraints
	segtree sgt;
	sgt.init(MXC);
	
	ll ans = 0;
	for(auto p: plats){
		ans += p[0] - sgt.get(p[1]);
		ans += p[0] - sgt.get(p[2]-1);
		sgt.add(p[1], p[2], p[0]);
	}
	
	cout << ans << endl;
	
	return 0;
}