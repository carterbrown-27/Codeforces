#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

struct segtree {
	int size;
	vector<pair<int,int>> sums;
	pair<int,int> DEFVAL = make_pair((int)1e9,0);
	
	pair<int,int> assoc(pair<int,int> a, pair<int,int> b){
		if(a.first < b.first) return a;
		if(b.first < a.first) return b;
		return make_pair(a.first, a.second + b.second);
	}
	
	void init(int n){
		size = 1;
		while(size < n) size*=2;
		sums.assign(2*size, DEFVAL);
	}
	
	void init(vector<int> &a){
		init(a.size());
		build(a);
	}
	
	void build(vector<int> &a, int x, int lx, int rx){
		// if in bottom layer, check if within "actual" elems (not added 0s)
		if(rx-lx == 1){
			if(lx < a.size()){
				sums[x] = make_pair(a[lx],1);
			}
			return;
		}
		int m = (lx + rx) / 2;
		build(a, 2*x + 1, lx, m);
		build(a, 2*x + 2, m, rx);
		
		sums[x] = assoc(sums[2*x+1], sums[2*x+2]);
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
			sums[x] = make_pair(v,1);
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
	
	pair<int,int> sum(int l, int r){
		return sum(l, r, 0, 0, size);
	}
	
	pair<int,int> sum(int l, int r, int x, int lx, int rx){
		
		// segment is completely outside
		if(rx <= l || lx >= r) return DEFVAL;
		
		// segment is completely contained
		if(l <= lx && rx <= r) return sums[x];
		
		// segment is partially contained (recursive case)
		int m = (lx+rx)/2;
		
		return assoc(sum(l, r, 2*x + 1, lx, m), sum(l, r, 2*x + 2, m, rx));
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
			auto p = sgt.sum(a,b);
			cout << p.first << " " << p.second << endl;
		}
	}
}

int main() {
	solve();
	return 0;
}