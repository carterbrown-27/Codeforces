#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	// not working.
	int n;
	cin >> n;
	double adb[n];
	for(int i = 0; i < n; i++){
		double a,b;
		cin >> a >> b;
		adb[i] = a/b;
	}

	map<double,int> exclTally;
	for(int i = 0; i < n; i++){
		exclTally[adb[i]]++;
	}

	int MOD = 1000000007;
	ll ans = 0;
	for(auto p: exclTally){
		// something?
	}
	
	cout << (ans % MOD) << endl;
}

int main() {
	solve();
	return 0;
}