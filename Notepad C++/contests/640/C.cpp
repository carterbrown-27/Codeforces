#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int n,k;
	cin >> n >> k;
	int ans = 0;
	int d = k;
	while(d>0){
		int s = ans;
		ans+=d;
		d=(d+s%n)/n;
	}
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}