#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	ll n = 0;
	for(int x = a; x <= b; x++){
		// trying to find formula to get rid of this loop
		for(int y = max(c-x+1,b); y <= c; y++){
			n += min(d-c+1,x+y-c);
		}
	}
	
	cout << n << endl;
}

int main() {
	solve();
	return 0;
}