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

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

void solve() {
	int n, m;
	cin >> n >> m;
	
	int p = n*m;
	
	int a[p];
	for(int i = 0; i < p; i++){
		cin >> a[i];
	}
	
	vector<int> v;
	for(int i = 0; i < p; i++){
		v.pb(a[i]);
	}
	
	// need to be in this order
	sort(v.begin(), v.end());
	
	map<int,int> mp;
	for(int i = 0; i < p; i++){
		if(mp.find(v[i]) == mp.end()){
			mp[v[i]] = i;
		}
	}
	
	map<int,minpq<pair<int,int>>> avail;
	for(int i = 0; i < p; i++){
		avail[v[i]].push({i/m, -(i%m)});
	}
	
	int ans = 0;
	vector<FenwickTree> fw(n, FenwickTree(m));
	
	for(int t = 0; t < p; t++){
		auto cur = avail[a[t]].top();
		int i = cur.first, j = -cur.second;
		int cost = fw[i].sum(j);
		ans += cost;
		
		fw[i].add(j,1);
		avail[a[t]].pop();
	}
	
	cout << ans << endl;
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