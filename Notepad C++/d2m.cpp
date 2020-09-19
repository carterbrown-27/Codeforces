#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	ll o = 1, e = 2, sum = 0;
	while(e <= 4e12){
		sum += e;
		ll t = o+e;
		o += 2*e;
		e += 2*t;
	}
	
	cout << sum << endl;
}

int main() {
	solve();
	return 0;
}