#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int a, b, k;
	cin >> a >> b >> k;
	
	map<int, int> as, bs;
	
	int pb[k], pg[k];
	for(int i = 0; i < k; i++) cin >> pb[i];
	for(int i = 0; i < k; i++) cin >> pg[i];
	
	ll ans = 0;
	for(int i = 0; i < k; i++){
		ans += i - as[pb[i]] - bs[pg[i]];
		as[pb[i]]++;
		bs[pg[i]]++;
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