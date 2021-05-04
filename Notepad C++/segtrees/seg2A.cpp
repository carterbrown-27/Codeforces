#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

template<typename T>
struct segtree {
	struct node {
		ll mx, pref, suf, sum;
		node(T m=0, T p=0, T s=0, T sm=0) : mx(m), pref(p), suf(s), sum(sm) {}
	};
	
	int size;
	vector<node> sums;
	static const int DV = 0;
	
	void init(int n){
		size = 1;
		while(size < n) size*=2;
		sums.resize(2*size);
	}
	
	void init(vector<int> &a){
		init(a.size());
		build(a);
	}
	
	void build(vector<int> &a, int x, int lx, int rx){
		// if in bottom layer, check if within "actual" elems (not added 0s)
		if(rx-lx == 1){
			if(lx < a.size()){
				sums[x].sum = a[lx];
				sums[x].pref = sums[x].suf = sums[x].mx = max(0, a[lx]);
			}
			return;
		}
		int m = (lx + rx) / 2;
		build(a, 2*x + 1, lx, m);
		build(a, 2*x + 2, m, rx);
		
		updateNode(sums[x], sums[2*x+1], sums[2*x+2]);
	}
	
	void build(vector<int> &a){
		build(a, 0, 0, size);
	}
	
	void set(int i, int v){
		if(i < 0 || i >= size) return;
		set(i, v, 0, 0, size);
	}
	
	void set(int i, int v, int x, int lx, int rx){
		// if x is a leaf, set it directly
		if(rx-lx == 1){
			sums[x].sum = v;
			sums[x].pref = sums[x].suf = sums[x].mx = max(0, v);
			return;
		}
		
		int m = (lx+rx)/2;
		// i is in left
		if(i < m){
			// goto left node
			set(i, v, 2*x + 1, lx, m);
		}else{
			// goto right node
			set(i, v, 2*x + 2, m, rx);
		}
		
		// doesn't go o.o.b as x is not a leaf
		updateNode(sums[x], sums[2*x+1], sums[2*x+2]);
	}
	
	void updateNode(node &n, node &l, node &r){
		n.sum = l.sum + r.sum;
		//cout << n.mx << " -> ";
		n.mx = max({l.mx, r.mx, l.suf + r.pref});
		//cout << n.mx << endl;
		n.pref = max(l.pref, l.sum + r.pref);
		n.suf = max(r.suf, l.suf + r.sum);
	}
	
	T sum(int l, int r){
		return sums[0].mx;
	}
	
	/*
	T sum(int l, int r, int x, int lx, int rx){
		// segment is completely outside
		if(rx <= l || lx >= r) return 0;
		
		// segment is completely contained
		if(l <= lx && rx <= r){
			return sums[x].mx;
		} 
		
		// segment is partially contained (recursive case)
		int m = (lx+rx)/2;
		
		return sum(l, r, 2*x + 1, lx, m) + sum(l, r, 2*x + 2, m, rx);
	}
	*/
};

void solve() {
	int n, m;
	cin >> n >> m;
	
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	
	segtree<ll> sgt;
	sgt.init(v);
	
	cout << sgt.sum(0,sgt.size) << endl;
	
	for(int x = 0; x < m; x++){
		int i, v;
		cin >> i >> v;
		
		sgt.set(i,v);
		cout << sgt.sum(0,sgt.size) << endl;
	}
}

int main() {
	solve();
	return 0;
}