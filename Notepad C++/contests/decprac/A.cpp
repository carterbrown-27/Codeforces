#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int a,b,c;
	cin >> a >> b >> c;
	int s = a+b+c;
	cout << ((s % 9 == 0) && (s/9 <= min(min(a,b),c)) ? "YES" : "NO") << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}