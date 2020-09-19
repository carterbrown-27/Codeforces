#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int n = 1e6;
	// cin >> n;
	ll sum = n*(n+1)/2;
	ll sqsum = n*(n+1)*(2*n + 1)/6;
	
	cout << (sum*sum)-sqsum << endl;
	// 131906964621155232
}

int main() {
	solve();
	return 0;
}