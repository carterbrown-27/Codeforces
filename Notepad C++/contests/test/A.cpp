#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int n,k;
	if(n%2 != k%2 || 1ll*k*k > n){
		cout << "NO" << endl;
	}else{
		cout << "YES" << endl;
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}