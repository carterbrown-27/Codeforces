#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int n,m,k;
	cin >> n >> m >> k;
	int f = min(n/k, m);
	int s = 0;
	if(m > n/k){
		s = ceil(((double) m-f)/(k-1));
	}
	
	cout << (f-s) << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}