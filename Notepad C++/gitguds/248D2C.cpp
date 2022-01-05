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
	
	int n, m;
	cin >> n >> m;
	
	int a[m];
	for(int i = 0; i < m; i++)
		cin >> a[i];
	
	umap<int, vector<int>> mp;
	for(int i = 0; i < m; i++){
		if(i > 0 && a[i-1] != a[i])
			mp[a[i]].pb(a[i-1]);
		if(i < m-1 && a[i+1] != a[i])
			mp[a[i]].pb(a[i+1]);
	}
	
	int best = -1, bMdi = -1;
	ll mx = 0;
	for(auto& p: mp){
		auto v = p.second;
		sort(v.begin(), v.end());
		
		int mdi = v[v.size()/2];
		ll diff = 0;
		for(int x: v)
			diff += abs(p.first-x) - abs(mdi-x);
		
		if(diff > mx){
			mx = diff;
			best = p.first;
			bMdi = mdi;
		}
		// cout << p.first << " " << mdi << " " << diff << endl;
	}
	
	for(int i = 0; i < m; i++)
		if(a[i] == best)
			a[i] = bMdi;
	
	// cout << best << " " << bMdi << endl;
		
	ll ans = 0;
	for(int i = 1; i < m; i++)
		ans += abs(a[i]-a[i-1]);
	
	cout << ans << endl;
	return 0;
}