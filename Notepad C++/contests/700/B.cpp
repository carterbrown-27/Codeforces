#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int A, B, n;
	cin >> A >> B >> n;
	
	ll sum = 0;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	int b[n];
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}
	
	int mx = 0;
	for(int i = 0; i < n; i++){
		ll attacks = (b[i] + A-1) / A;
		sum += attacks * a[i];
		mx = max(mx, a[i]);
	}
	
	cout << (sum < B + mx ? "YES" : "NO") << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}