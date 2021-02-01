#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

int gcd(int a, int b){
	if(b == 0) return a;
	gcd(b, a % b);
}

void solve() {
	int n;
	cin >> n;
	
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	
	
	int q;
	cin >> q;
	for(int i = 0; i < q; i++){
		ll w;
		cin >> w;
		
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