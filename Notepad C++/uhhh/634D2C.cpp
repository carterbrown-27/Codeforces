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
	
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	
	ll ans = 0;
	for(ll z = c; z <= d; z++){
		ll v = (c*(c+1) - (b-1)*b)/2 + (c-b)*max(0LL,b-a-z+1);
		// cout << v << " ";
		if(v>0) ans += v;
	}
	
	cout << ans << endl;
	return 0;
}