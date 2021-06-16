#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

const int MOD = 1e9 + 7;

// Mass-Change Segment Tree
template <typename T>
struct segtree {
	struct node {
		ll mx, pref, suf, sum;
		node(T m=0, T p=0, T s=0, T sm=0) : mx(m), pref(p), suf(s), sum(sm) {}
	};
	
	int size;
	vector<T> sums; // op
	vector<node> res; // calcOp
	static T DV, NONE;
	
	void apply(node &a, T b, int len){
		if(b==NONE) return;
		a.sum = b*len;
		a.pref = a.suf = a.mx = max(a.sum, 0LL);
	}
	
	void apply(T &a, T b){
		if(b==NONE) return;
		a = b;
	}
	
	void init(int n){
		size = 1;
		while(size < n) size*=2;
		res.assign(2*size, 0);
		sums.assign(2*size, 0);
	}
	
	void prop(int x, int lx, int rx){
		if(rx-lx == 1) return;
		int m = (lx+rx)/2;
		apply(sums[2*x+1], sums[x]);
		apply(res[2*x+1], sums[x], m-lx);
		apply(sums[2*x+2], sums[x]);
		apply(res[2*x+2], sums[x], rx-m);
		
		// updateNode(res[x], res[2*x+1], res[2*x+2]);
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
			apply(res[x], v, rx-lx);
			return;
		} 
		
		// segment is partially contained (recursive case)
		int m = (lx+rx)/2;
		add(l, r, v, 2*x+1, lx, m);
		add(l, r, v, 2*x+2, m, rx);
		
		updateNode(res[x], res[2*x+1], res[2*x+2]);
	}
	
	void updateNode(node &n, node &l, node &r){
		n.sum = l.sum + r.sum;
		n.mx = max({l.mx, r.mx, l.suf + r.pref});
		n.pref = max(l.pref, l.sum + r.pref);
		n.suf = max(r.suf, l.suf + r.sum);
	}
	
	T calc(){
		return res[0].mx;
	}
};

template<> ll segtree<ll>::DV = 0;
template<> ll segtree<ll>::NONE = LLONG_MAX;

void solve() {
	int n, m;
	cin >> n >> m;
	
	segtree<ll> sgt;
	sgt.init(n);
	
	for(int q = 0; q < m; q++){
		int l, r, v;
		cin >> l >> r >> v;
		sgt.add(l,r,v);
		cout << sgt.calc() << endl;
	}
}

int main() {
	solve();
	return 0;
}