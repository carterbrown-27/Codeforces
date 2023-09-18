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

int main() {
	ios::sync_with_stdio(false);
	
	int n, d, m;
	cin >> n >> d >> m;
	
	vector<int> a(n);
	for(int& x: a){
		cin >> x;
	}
	
	vector<int> le;
	vector<int> g;
	for(int x: a){
		if(x > m){
			g.pb(x);
		}else{
			le.pb(x);
		}
	}
	
	sort(le.begin(), le.end(), greater<int>());
	sort(g.begin(), g.end(), greater<int>());
	
	auto calc_prf = [&](vector<int>& nums, vector<ll>& prf){
		for(int i = 1; i <= n; i++){
			prf[i] = prf[i-1] + (i-1 < nums.size() ? nums[i-1] : 0);
		}
	};
	
	vector<ll> unb(n+1);
	calc_prf(le, unb);
	
	vector<ll> ban(n+1);
	calc_prf(g, ban);
	
	int mxb = (n+d)/(d+1);
	ll ans = 0;
	// search over # of bans
	for(int b = 0; b <= mxb; b++){
		// take ban on last day, then take b-1 bans which take d+1 days each (incl. posting day)
		int u = n;
		if(b > 0)
			u -= (b-1)*(d+1) + 1;
		
		ll cur = ban[b];
		if(u > 0)
			cur += unb[u];
		
		// cout << b << " " << u << " " << cur << endl;
		ans = max(ans, cur);
	}
	
	cout << ans << endl;
	return 0;
}