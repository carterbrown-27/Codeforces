#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int n;
	cin >> n;
	
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	ll p[n];
	ll mx = 0;
	for(int i = n; i-- > 0;){
		p[i] = a[i];
		int j = i + a[i];
		if(j < n) p[i] += p[j];
		
		mx = max(mx, p[i]);
	}
	
	cout << mx << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}