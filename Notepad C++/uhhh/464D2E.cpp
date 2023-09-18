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
    vector<ll> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    ll sum(int r) {
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    ll sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int main() {
	ios::sync_with_stdio(false);
	
	int Q;
	cin >> Q;
	
	vector<pair<bool,int>> queries(Q);
	vector<int> v;
	for(auto &p: queries){
		int t;
		cin >> t;
		p.first = (t == 2);
		if(!p.first){
			cin >> p.second;
			v.pb(p.second);
		}
	}
	
	
	// see if this co-ord compression needs fixing
	// should we not assign diff co-ords to same values
	// for tern search mean({3,3}) = mean({3,3,3}) --> f(m) = f(m+1)?
	// update: yes, this was the problem
	sort(v.begin(), v.end());
	umap<int,int> cc;
	int prev = -1, cur = 0;
	for(auto &x: v){
		if(x != prev)
			cc[x] = cur++;
		prev = x;
	}
	
	size_t n = cc.size();
	
	FenwickTree sums(n);
	FenwickTree cnt(n);
	int mx = 0, mn = v.size();
	for(const auto& [t, x] : queries){
		if(t){
			// ternary search for min mean?
			auto f = [&](int x) -> double {
				int big = (x < cc[mx] ? mx : 0);
				int amt = cnt.sum(x);
				return (double) (sums.sum(x) + big) / (amt + (big > 0));
			};
			
			int l = cc[mn]-1, r = cc[mx];
			while(r-l > 1){
				int m = (l+r)/2;
				if(f(m) < f(m+1)){
					r = m;
				}else{
					l = m;
				}
			}
			// cout << mx << " " << l+1 << " " << f(l+1) << endl;
			cout << fixed << setprecision(10) << mx - f(l+1) << endl;
		}else{
			sums.add(cc[x], x);
			cnt.add(cc[x], 1);
			mx = max(mx, x);
			mn = min(mn, x);
		}
	}
	
	return 0;
}

