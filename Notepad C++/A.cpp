#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int n, k;
	cin >> n >> k;
	
	int target = n + (n % k > 0 ? k - n%k : 0);
	
	cout << target/n + (target%n > 0) << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}