#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	ll time = b;
	a-=min(a,b);
	if(a>0){
		if(c<=d){
			time = -1;
		}else{
			ll x = (ll) ceil((double)a/(c-d));
			time += x*c;
		}
	}
	cout << time << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}