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
	
	sort(v.begin(), v.end());
	
	map<int,int> mp;
	for(int i = 0; i < p; i++){
		if(mp.find(v[i]) == mp.end()){
			mp[v[i]] = i;
		}
	}
	
	int b[p];
	for(int i = 0; i < p; i++){
		b[i] = mp[a[i]];
		
	}
	
	vector<int> eq(p, 0);
	for(int i = 0; i < p; i++)
		eq[b[i]]++;
	
	for(int x: eq){
		cout << x << " ";
	}
	cout << endl;
	
	
	int ans = 0;
	FenwickTree fw(p);
	for(int i = 0; i < p; i++){
		// consider eq
		int lt = fw.sum(b[i]-1)%m;
		// cout << lt << " " << eq << endl;
		ans += (eq[b[i]]-1 >= m-lt ? 0 : lt);
		fw.add(b[i], 1);
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