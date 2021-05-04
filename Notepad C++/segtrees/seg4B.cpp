#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

int MOD;

struct matrix {
	int vals[2][2];
	
	friend ostream& operator<<(ostream& out, const matrix& mat); 
};

ostream& operator<<(ostream& out, const matrix& mat){
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			out << mat.vals[i][j] << " ";
		}
		out << "\n";
	}
	return out;
}

template <typename T>
struct segtree {
	
	int size;
	vector<T> sums;
	matrix DV;
	
	T assoc(T a, T b){
		// TODO consider making matrix product template
		matrix res;
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 2; j++){
				int sum = 0;
				for(int x = 0; x < 2; x++){
					sum += a.vals[i][x] * b.vals[x][j];
				}
				
				res.vals[i][j] = sum % MOD;
			}
		}
		return res;
	}
	
	void init(int n){
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
				DV.vals[i][j] = (i==j);
		size = 1;
		while(size < n) size*=2;
		sums.resize(2*size);
	}
	
	void init(vector<T> &a){
		init(a.size());
		build(a);
	}
	
	void build(vector<T> &a, int x, int lx, int rx){
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
	
	void build(vector<T> &a){
		build(a, 0, 0, size);
	}
	
	void set(int i, T v){
		if(i < 0 || i >= size) return;
		set(i, v, 0, 0, size);
	}
	
	void set(int i, T v, int x, int lx, int rx){
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
	cin >> MOD;
	
	int n, m;
	cin >> n >> m;
	
	vector<matrix> v(n);
	
	for(int x = 0; x < n; x++)
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
				cin >> v[x].vals[i][j];
	
	segtree<matrix> sgt;
	sgt.init(v);
	
	for(int q = 0; q < m; q++){
		int l, r;
		cin >> l >> r;
		cout << sgt.sum(l-1,r) << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}