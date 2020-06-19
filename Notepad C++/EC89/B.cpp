#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int n,x,m;
	cin >> n >> x >> m;
	int l = x;
	int r = x;
	for(int i = 0; i < m; i++){
		int ml, mr;
		cin >> ml >> mr;
		if((ml <= l && l <= mr)||(ml <= r && r<= mr)){
			l = min(l,ml);
			r = max(r,mr);
		}
	}
	
	cout << r-l+1 << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}