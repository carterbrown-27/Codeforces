#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int n;
	cin >> n;
	
	vector<int> a;
	int d = 0;
	
	for(int i = 0; i < n; i++){
		char c;
		cin >> c;
		a.pb(c-'0');
	}
	
	for(int i = 0; i < n; i++){
		char c;
		cin >> c;
		int v = c-'0';
		d += (v > a[i] ? -1 : (v < a[i]));
	}
	
	cout << (d == 0 ? "EQUAL" : (d > 0 ? "RED" : "BLUE")) << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}