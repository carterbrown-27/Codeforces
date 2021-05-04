#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	ll r, g, b;
	cin >> r >> g >> b;
	
	cout << min((r+g+b)/3, r+g+b-max(r,max(g,b))) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}