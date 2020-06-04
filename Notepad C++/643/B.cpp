#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int n;
	cin >> n;
	
	int e[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &e[i]);
	}
	
	sort(e, e+n);
	
	int g = 0;
	for(int i = 0; i < n; i++){
		// cout << i << endl;
		int mx = e[i];
		for(int j = 0; j < mx; j++){
			mx = max(e[i+j],mx);
			// cout << e[i] << " " << mx << endl;
			if(i+mx > n){
				cout << g << endl;
				return;
			}
		}
		i+=mx-1;
		g++;
	}
	
	cout << g << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}