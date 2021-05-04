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
	
	T find(int i){
		return find(i, 0, 0, size);
	}
	
	T find(int i, int x, int lx, int rx){	
		if(rx-lx == 1){
			return (sums[x] >= i) ? lx : -1;
		} 
		
		int l = sums[2*x + 1];
		int m = (lx+rx)/2;
		
		if(l < i){
			// R
			return find(i, 2*x + 2, m, rx);
		}else{
			// L
			return find(i, 2*x + 1, lx, m);
		}
	}
};

void solve() {
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
			int x;
			cin >> x;
			cout << sgt.find(x) << endl;
		}
	}
}

int main() {
	solve();
	return 0;
}