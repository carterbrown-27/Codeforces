#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int n, k;
	cin >> n >> k;
	
	ll f;
	cin >> f;
	
	ll sum = 0;
	for(int i = 1; i < n; i++){
		ll v;
		cin >> v;
		
		if(v*100 > f*k){
			ll nf = (v*100)/k + ((v*100)%k > 0);
			sum += nf-f;
			f = nf;
		}
		
		f += v;
	}
	
	cout << sum << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}