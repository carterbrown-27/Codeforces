#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

// Mass-Change Segment Tree
template <typename T>
struct segtree {
	
	int size;
	vector<T> sums; // op
	vector<T> res; // calcOp
	static T DV;
	
	T op(T a, T b){
		return a + b;
	}
	
	void apply(T &a, T b){
		a = op(a,b);
	}
	
	T calcOp(T a, T b){
		return std::min(a,b);
	}
	
	void init(int n){
		size = 1;
		while(size < n) size*=2;
		sums.assign(2*size, 0);
		res.assign(2*size, 0);
	}
	
	T get(int i){
		if(i < 0 || i >= size) return -1;
		return get(i, 0, 0, size);
	}
	
	T get(int i, int x, int lx, int rx){
		// if x is a leaf, set it directly
		if(rx-lx == 1){
			return sums[x];
		}
		
		int m = (lx+rx)/2;
		// i is in left
		if(i < m){
			// goto left node
			return op(sums[x], get(i, 2*x + 1, lx, m));
		}else{
			// goto right node
			return op(sums[x],  get(i, 2*x + 2, m, rx));
		}
	}
	
	void add(int l, int r, int v){
		return add(l, r, v, 0, 0, size);
	}
	
	void add(int l, int r, int v, int x, int lx, int rx){
		
		// segment is completely outside
		if(rx <= l || lx >= r) return;
		
		// segment is completely contained
		if(l <= lx && rx <= r){
			apply(sums[x], v);
			apply(res[x], v);
			return;
		} 
		
		// segment is partially contained (recursive case)
		int m = (lx+rx)/2;
		add(l, r, v, 2*x+1, lx, m);
		add(l, r, v, 2*x+2, m, rx);
		
		res[x] = op(calcOp(res[2*x+1], res[2*x+2]), sums[x]);
	}
	
	T calc(int l, int r){
		return calc(l, r, 0, 0, size);
	}
	
	T calc(int l, int r, int x, int lx, int rx){
		
		// segment is completely outside
		if(rx <= l || lx >= r) return DV;
		
		// segment is completely contained
		if(l <= lx && rx <= r){
			return res[x];
		} 
		
		// segment is partially contained (recursive case)
		int m = (lx+rx)/2;
		return op(calcOp(calc(l, r, 2*x+1, lx, m), calc(l, r, 2*x+2, m, rx)), sums[x]);
	}
};

template<> ll segtree<ll>::DV = LLONG_MAX;

void solve() {
	int n, m;
	cin >> n >> m;
	
	segtree<ll> sgt;
	sgt.init(n);
	
	for(int q = 0; q < m; q++){
		int o;
		cin >> o;
		if(o == 1){
			int l, r, v;
			cin >> l >> r >> v;
			sgt.add(l,r,v);
		}else if(o == 2){
			int l, r;
			cin >> l >> r;
			cout << sgt.calc(l,r) << endl;
		}
	}
}

int main() {
	solve();
	return 0;
}