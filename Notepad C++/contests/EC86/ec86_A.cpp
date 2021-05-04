#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int x,y,a,b;
	cin >> x >> y >> a >> b;
	ll ans = 0;
	if(b<=a*2&&(x>0)==(y>0)){
		ll mn = min(x,y);
		x-=mn;
		y-=mn;
		ans+=abs(mn)*b;
	}
	ans+=(ll)abs(x)*a;
	ans+=(ll)abs(y)*a;
	
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