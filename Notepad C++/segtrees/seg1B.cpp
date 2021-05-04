#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

#define MAX_N 1e9+1

struct segtree {
	int size;
	vector<int> mins;
	
	void init(int n){
		size = 1;
		while(size < n) size*=2;
		mins.assign(2*size, MAX_N);
	}
	
	void init(vector<int> &a){
		init(a.size());
		build(a);
	}
	
	void build(vector<int> &a, int x, int lx, int rx){
		// if in bottom layer, check if within "actual" elems (not added 0s)
		if(rx-lx == 1){
			if(lx < a.size()){
				mins[x] = a[lx];
			}
			return;
		}
		int m = (lx + rx) / 2;
		build(a, 2*x + 1, lx, m);
		build(a, 2*x + 2, m, rx);
		
		mins[x] = std::min(mins[2*x+1],mins[2*x+2]);
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
			mins[x] = v;
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
		mins[x] = std::min(mins[2*x+1], mins[2*x+2]);
	}
	
	ll min(int l, int r){
		return min(l, r, 0, 0, size);
	}
	
	ll min(int l, int r, int x, int lx, int rx){
		
		// segment is completely outside
		if(rx <= l || lx >= r) return MAX_N;
		
		// segment is completely contained
		if(l <= lx && rx <= r) return mins[x];
		
		// segment is partially contained (recursive case)
		int m = (lx+rx)/2;
		
		return std::min(min(l, r, 2*x + 1, lx, m), min(l, r, 2*x + 2, m, rx));
	}
};

void solve() {
	int n, m;
	cin >> n >> m;
	
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	
	segtree sgt;
	sgt.init(v);
	
	for(int i = 0; i < m; i++){
		int o, a, b;
		cin >> o >> a >> b;
	
		if(o == 1){
			sgt.set(a,b);
		}else if(o == 2){
			cout << sgt.min(a,b) << endl;
		}
	}
}

int main() {
	solve();
	return 0;
}