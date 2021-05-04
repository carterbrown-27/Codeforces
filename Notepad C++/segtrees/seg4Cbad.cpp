#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

template <typename T>
struct segtree {
	static const int MXA = 40;
	int size;
	vector<T> sums;
	vector<int> DV;
	
	T assoc(T a, T b){
		vector<int> res(MXA+1);
		for(int i = 1; i <= MXA; i++)
			res[i] = a[i] + b[i];
		return res;
	}
	
	void init(int n){
		DV.assign(MXA+1, 0);
		size = 1;
		while(size < n) size*=2;
		sums.assign(2*size, vector<int>(MXA+1, 0));
	}
	
	void init(vector<int> &a){
		init(a.size());
		build(a);
	}
	
	void build(vector<int> &a, int x, int lx, int rx){
		// if in bottom layer, check if within "actual" elems (not added 0s)
		if(rx-lx == 1){
			if(lx < a.size()){
				sums[x][a[lx]]++;
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
			sums[x].assign(MXA, 0);
			sums[x][v]++;
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
};

void solve() {
	int n, m;
	cin >> n >> m;
	
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	segtree<vector<int>> sgt;
	sgt.init(a);
	
	for(int q = 0; q < m; q++){
		int t,x,y;
		cin >> t >> x >> y;
		if(t == 1){
			vector<int> v = sgt.sum(x-1, y);
			
			
			cout << ans << endl;
		}else{
			sgt.set(x-1, y);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}