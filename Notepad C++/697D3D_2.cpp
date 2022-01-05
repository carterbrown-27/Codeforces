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

void calcPrefix(vector<int>& src, vector<ll>& prf)
{
	sort(src.begin(), src.end(), greater<int>());
	prf.resize(src.size()+1);
	prf[0] = 0;
	for(int i = 0; i < src.size(); i++)
		prf[i+1] = prf[i] + src[i];
}

void solve() {
	int n, m;
	cin >> n >> m;
	
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];

	vector<int> rv, iv;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(x == 1){
			rv.pb(a[i]);
		}else{
			iv.pb(a[i]);
		}
	}
	
	vector<ll> rp, ip;
	calcPrefix(rv,rp);
	calcPrefix(iv,ip);
	
	const int MAX = 1e9;
	int mn = MAX;
	for(int i = 0; i < ip.size(); i++){
		// bsearch
		auto it = lower_bound(rp.begin(), rp.end(), m - ip[i]);
		if(it == rp.end()) continue;
		mn = min(mn, i*2 + (it-rp.begin()));
	}
	
	cout << (mn < MAX ? mn : -1) << endl;
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