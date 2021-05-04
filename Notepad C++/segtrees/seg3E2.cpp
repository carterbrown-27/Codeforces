#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

template <typename T>
struct segtree {
	
	int size;
	vector<T> sums;
	static const int DV = 0;
	
	T assoc(T a, T b){
		return a + b;
	}
	
	void init(int n){
		size = 1;
		while(size < n) size*=2;
		sums.assign(2*size, DV);
	}
	
	void set(int i, T v){
		if(i < 0 || i >= size) return;
		set(i, v, 0, 0, size);
	}
	
	void set(int i, T v, int x, int lx, int rx){
		// if x is a leaf, set it directly
		if(rx-lx == 1){
			sums[x] += v;
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
		sums[x] = assoc(sums[2*x+1], sums[2*x+2]);
	}
	
	void add(int l, int r, int v){
		set(l, v);
		set(r, -v);
	}
	
	T sum(int l, int r){
		return sum(l, r, 0, 0, size);
	}
	
	T sum(int l, int r, int x, int lx, int rx){
		
		// segment is completely outside
		if(rx <= l || lx >= r) return DV;
		
		// segment is completely contained
		if(l <= lx && rx <= r) return sums[x];
		
		// segment is partially contained (recursive case)
		int m = (lx+rx)/2;
		
		return assoc(sum(l, r, 2*x + 1, lx, m), sum(l, r, 2*x + 2, m, rx));
	}
	
	T get(int i){
		return sum(0,i+1);
	}
};

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
			int i;
			cin >> i;
			cout << sgt.get(i) << endl;
		}
	}
}

int main() {
	solve();
	return 0;
}