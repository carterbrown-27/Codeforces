#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

#define pb push_back

void genPows(ll x, vector<ll>& v){
	ll xc = 1;
	while(true){
		v.pb(xc);
		if(xc > 1e18/x) break;
		xc *= x;
	}
}

void solve() {
	ll x,y,l,r;
	cin >> x >> y >> l >> r;
	
	vector<ll> xpows, ypows;
	genPows(x, xpows);
	genPows(y, ypows);
	
	set<ll> sums;
	for(int i = 0; i < xpows.size(); i++){
		for(int j = 0; j < ypows.size(); j++){
			ll val = xpows[i]+ypows[j];
			if(l <= val && val <= r) sums.insert(val);
		}
	}
	
	ll mx = 0;
	ll prev = l-1;
	for(ll v: sums){
		// cout << v << "-" << prev << endl;
		mx = max(v-1-prev, mx);
		prev = v;
	}
	
	cout << max(mx, r-prev) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}