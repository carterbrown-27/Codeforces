#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int x,y,n;
	cin >> x >> y >> n;
	int mx = (n/x)*x;
	int ans = y;
	if(mx+y <= n){
		ans = mx+y;
	}else{
		ans = mx-(x-y);
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