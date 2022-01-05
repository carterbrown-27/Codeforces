#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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

int main() {
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(int &x: a)
		cin >> x;
	
	int ans = 0;
	FenwickTree fw(n);
	// -val, n-idx
	minpq<pair<int,int>> pq;
	
	for(int i = 0; i < n; i++){
		if(a[i] >= 0){
			fw.add(i, a[i]);
			ans++;
		}else{
			pq.push({-a[i], n-i});
		}
	}
	
	while(!pq.empty()){
		auto &p = pq.top();
		int v = p.first, idx = n-p.second;
		int hp = fw.sum(idx);
		if(hp - v >= 0){
			cout << hp << " " << idx << " " << v << endl;
			ans++;
			fw.add(idx, -v);
		}
		pq.pop();
	}
	
	cout << ans << endl;
	return 0;
}