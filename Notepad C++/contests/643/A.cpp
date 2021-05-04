#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	ll a, k;
	cin >> a >> k;
	for(ll c = 1; c < k; c++){
		ll mn = 10;
		ll mx = 0;
		ll t = a;
		while(t>0){
			mn = min(mn,t%10);
			mx = max(mx,t%10);
			t/=10;
		}
		
		if(mn*mx == 0){
			break;
		}else{
			a+=(mn*mx);
			//cout << a << endl;
		}
	}
	cout << a << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}