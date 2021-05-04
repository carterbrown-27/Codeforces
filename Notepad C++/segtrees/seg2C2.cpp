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
	
	inline T assoc(T a, T b){
		return max(a,b);
	}
	
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
				sums[x] = a[lx];
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
			sums[x] = v;
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
	
	T find(int x, int l){
		return find(x, l, 0, 0, size);
	}
	
	T find(int i, int l, int x, int lx, int rx){
		if(rx <= l) return -1;
		if(sums[x] < i) return -1;
		
		if(rx-lx == 1){
			// cout << sums[x] << endl;
			return lx;
		} 
		
		int m = (lx+rx)/2;
		
		// L first
		T res = find(i, l, 2*x + 1, lx, m);
		if(res != -1) return res;
		
		// then R
		return find(i, l, 2*x + 2, m, rx);
	}
};

void solve() {
	ios::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	
	segtree<int> sgt;
	sgt.init(v);
	
	for(int i = 0; i < m; i++){
		int o;
		cin >> o;
	
		if(o == 1){
			int i,v;
			cin >> i >> v;
			sgt.set(i,v);
		}else if(o == 2){
			int x, l;
			cin >> x >> l;
			cout << sgt.find(x,l) << endl;
		}
	}
}

int main() {
	solve();
	return 0;
}