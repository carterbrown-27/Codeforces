#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using uset = unordered_set<T>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

#define pb push_back

// ones/zeroes
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
	
	void set(int i){
		if(i < 0 || i >= size) return;
		set(i, 0, 0, size);
	}
	
	void set(int i, int x, int lx, int rx){
		// if x is a leaf, set it directly
		if(rx-lx == 1){
			sums[x] = 1;
			return;
		}
		
		int m = (lx+rx)/2;
		// i is in left
		if(i < m){
			// goto left node
			set(i, 2*x + 1, lx, m);
		}else{
			// goto right node
			set(i, 2*x + 2, m, rx);
		}
		
		// doesn't go o.o.b as x is not a leaf
		sums[x] = assoc(sums[2*x+1], sums[2*x+2]);
	}
	
	T sum(int l, int r){
		return sum(l, r, 0, 0, size);
	}
	
	T sum(int l, int r, int x, int lx, int rx){
		
		// segment is completely outside
		if(rx <= l || lx >= r) return 0;
		
		// segment is completely contained
		if(l <= lx && rx <= r) return sums[x];
		
		// segment is partially contained (recursive case)
		int m = (lx+rx)/2;
		
		return sum(l, r, 2*x + 1, lx, m) + sum(l, r, 2*x + 2, m, rx);
	}
};

void solve() {
	int n;
	cin >> n;
	
	segtree<int> sgt;
	sgt.init(2*n);
	
	vector<int> ls(n+1, -1);
	int res[n];
	
	for(int i = 0; i < 2*n; i++){
		int v;
		cin >> v;
		
		if(ls[v] == -1){
			ls[v] = i;
		}else{
			res[v-1] = sgt.sum(ls[v], i);
			sgt.set(ls[v]);
		}
	}
		
	for(int i = 0; i < n; i++)
		cout << res[i] << " ";
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}