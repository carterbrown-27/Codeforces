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

template <typename T>
struct segtree {
	
	int size;
	vector<T> sums;
	const int DV = 0;
	
	T assoc(T a, T b){
		return a + b;
	}
	
	void init(int n){
		size = 1;
		while(size < n) size*=2;
		sums.assign(2*size, DV);
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
	
	void set(int i, int v){
		if(i < 0 || i >= size) return;
		set(i, v, 0, 0, size);
	}
	
	void set(int i, int v, int x, int lx, int rx){
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
	int n;
	cin >> n;
	
	vector<int> b(n);
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}

	vector<int> tmp(b);
	sort(tmp.begin(), tmp.end());
	
	umap<int, int> ind;
	for(int i = 0; i < n; i++){
		ind[tmp[i]] = i;
	}
	
	// positions?
	int infs = 0, ninfs = 0, either = 0;
	segtree<int> sgt;
	sgt.init(n);
	
	for(int i = 0; i < n; i++){
		int p = ind[b[i]];
		int gt = sgt.sum(0, p), lt = sgt.sum(p+1, n), eq = sgt.sum(p,p+1);
		
		// cout << lt << " " << gt << " " << eq << endl;
		
		if(abs(gt-lt) < eq){
			// good already
			sgt.set(p, 2); // add another same
			either++;
		}else if((eq == 0 && abs(gt-lt) >= 2) || (eq > 0 && abs(gt-lt) - eq > 2)){
			// infinites
			if(lt > gt && lt-eq-infs-either <= gt){
				// add +infs
				// how
			}else if(gt > lt && gt-eq-ninfs-either <= lt){
				// add -infs
			}else{
				// bad
				cout << "NO" << endl;
				return;
			}
			sgt.set(p,2);
		}else{
			sgt.set(p, 2);
			if(lt > gt){
				infs += 1 + (eq != 0);
			}else{
				ninfs += 1 + (eq != 0);
			}
		}
	}
	
	cout << "YES" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}