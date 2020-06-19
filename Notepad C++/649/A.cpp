#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int n,x;
	cin >> n >> x;
	
	int a[n];
	int sum = 0;
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}
	
	if(sum % x != 0){
		cout << n << endl;
	}else{
		for(int i = 0; i < n; i++){
			if(a[i] % x != 0 || a[n-i-1] % x != 0){
				cout << n-i-1 << endl;
				return;
			}
		}
		
		// none found
		cout << -1 << endl;
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