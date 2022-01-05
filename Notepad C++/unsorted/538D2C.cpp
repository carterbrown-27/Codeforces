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
	
	ll n, b;
	cin >> n >> b;
	
	ll m, r;
	m = n/b;
	r = n%b;
	
	// factor b
	vector<int> facs;
	for(ll x = 1; x*x <= b; x++){
		if(b%x == 0){
			// facs.pb(x);
			facs.pb(b/x);
		}
	}
	cout << facs.size() << endl;
	
	reverse(facs.begin(), facs.end());
	
	ll ans = m * facs.size();
	
	int i;
	for(i = 0; i < facs.size() && r >= facs[i]; i++);
	// cout << i << endl;
	ans += i;
	
	ll p = b, e = 1;
	while(p <= 1e18/b && p*b <= n){
		p*=b;
		e++;
		ans += n/p;
	}
	// cout << e << endl;
	ans += e-1;
	
	cout << ans << endl;
	return 0;
}