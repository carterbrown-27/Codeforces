#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

#define pb push_back

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
	
	void add(int i, int v){
		if(i < 0 || i >= size) return;
		add(i, v, 0, 0, size);
	}
	
	void add(int i, int v, int x, int lx, int rx){
		// if x is a leaf, set it directly
		if(rx-lx == 1){
			sums[x]+=v;
			return;
		}
		
		int m = (lx+rx)/2;
		// i is in left
		if(i < m){
			// goto left node
			add(i, v, 2*x + 1, lx, m);
		}else{
			// goto right node
			add(i, v, 2*x + 2, m, rx);
		}
		
		// doesn't go o.o.b as x is not a leaf
		sums[x] = assoc(sums[2*x+1], sums[2*x+2]);
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
	
	int ordfind(int k, int x, int lx, int rx){
		//cout << k << " " << lx << " " << rx << endl;
		if(rx-lx == 1) return lx;
		int ls = sums[2*x+1];
		int m = (lx+rx)/2;
		if(ls >= k){
			return ordfind(k, 2*x+1, lx, m);
		}else{
			return ordfind(k-ls, 2*x+2, m, rx);
		}
	}
	
	int ordfind(int k){
		return ordfind(k, 0, 0, size);
	}
	
	void print(){
		cout << "===" << endl;
		int lv = 1, c = 0;
		for(int i = 0; i < sums.size()-1; i++){
			cout << sums[i] << " ";
			c++;
			if(c == lv){
				lv *= 2;
				c = 0;
				cout << endl;
			}
		}
		cout << "===" << endl;
	}
};


void solve() {
	int n,q;
	cin >> n >> q;
	
	vector<int> ac(n);
	for(int i = 0; i < n; i++){
		int v;
		cin >> v;
		ac[v-1]++;
	}
	
	segtree<ll> sgt;
	sgt.init(ac);
	
	//sgt.print();
	
	for(int i = 0; i < q; i++){
		int op;
		cin >> op;
		if(op < 0){
			int pos = sgt.ordfind(-op);
			sgt.add(pos, -1);
		}else{
			sgt.add(op-1, 1);
		}
		//sgt.print();
	}
	
	int ans = 0;
	
	for(int i = 0; i < n; i++){
		int val = sgt.sum(i,i+1);
		// cout << val << " ";
		if(val != 0){
			ans = i+1;
			// break;
		}
	}
	// cout << endl;
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}