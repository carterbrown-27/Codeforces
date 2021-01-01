#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int n;
	cin >> n;
	int k  = n/2;
	cout << (n & 1 ? (k + 1) * (k + 2) * 2 : (k + 1) * (k + 1)) << endl;
}

int main() {
	solve();
	return 0;
}