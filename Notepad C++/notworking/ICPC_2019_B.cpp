#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	ll k;
	cin >> k;
	if(k==1){
		cout << 0 << endl;
	}else if(k%2==1){
		// positive A
		cout << 1 << endl;
		cout << (k/2)*(k/2) << endl;
	}else{
		// negative A
		if(ceil(sqrt(k/2)) == sqrt(k/2)){
			cout << 1 << endl;
			cout << -k/2 << endl;
		}else{
			cout << 0 << endl;
		}
	}
}

int main() {
	solve();
	return 0;
}