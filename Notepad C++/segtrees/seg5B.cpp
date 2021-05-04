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
		return max(a,b);
	}
	
	void init(int n){
		size = 1;
		while(size < n) size*=2;
		sums.assign(2*size, DV);
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
			return assoc(sums[x], get(i, 2*x + 1, lx, m));
		}else{
			// goto right node
			return assoc(sums[x],  get(i, 2*x + 2, m, rx));
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
			sums[x] = assoc(sums[x], v);
			return;
		} 
		
		// segment is partially contained (recursive case)
		int m = (lx+rx)/2;
		add(l, r, v, 2*x+1, lx, m);
		add(l, r, v, 2*x+2, m, rx);
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