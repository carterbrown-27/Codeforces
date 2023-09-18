#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct point {
	int x,y;
};

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

template<typename T>
using uset = unordered_set<T>;

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
			sums[x] = 1 - sums[x];
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
	
	T find(int i){
		return find(i, 0, 0, size);
	}
	
	T find(int i, int x, int lx, int rx){	
		if(rx-lx == 1) return lx;
		
		int l = sums[2*x + 1];
		int m = (lx+rx)/2;
		
		if(l <= i){
			// R
			return find(i-l, 2*x + 2, m, rx);
		}else{
			// L
			return find(i, 2*x + 1, lx, m);
		}
	}
};

void solve() {
	int n;
    cin >> n;
    
    int a[n];
    priority_queue<pair<int,int>> pq;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        pq.push({a[i],-i});
    }
    
    int m;
    cin >> m;
    
    vector<tuple<int,int,int>> reqs(m);
    for(int i = 0; i < m; i++){
        int k, p;
        cin >> k >> p;
        reqs[i] = {k,p,i};
    }
    
    sort(reqs.begin(), reqs.end());
    
    segtree<int> sgt;
    sgt.init(n);
    
    int ans[m];
    int c = 0;
    for(auto& [k,p,i] : reqs){
        // cout << i << endl;
        // advance the state
        for(; c < k; c++){
            int i = -pq.top().second;
            // cout << "set " << i << endl;
            sgt.set(i);
            pq.pop();
        }
        
        int pos = sgt.find(p-1);
        // cout << "pos = " << pos << endl;
        ans[i] = a[pos];
    }
    
    for(int i = 0; i < m; i++){
        cout << ans[i] << "\n";
    }
    cout << std::flush;
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}