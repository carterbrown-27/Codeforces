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
	
	const int MAX_V = 1e9;
	int b[n];
	b[0] = a[0];
	for(int i = 1; i < n; i++){
		int mn, mx;
		if(a[i] >= b[i-1]){
			int q = a[i] / b[i-1];
			mn = q * b[i-1];
			mx = (q+1) * b[i-1];
		}else{
			// pick min
			mn = 1;
			mx = MAX_V + 1;
		}
		
		if(mx <= MAX_V && (mx - a[i] < a[i] - mn  || mn == 0)){
			b[i] = mx;
		}else{
			b[i] = mn;
		}
	}
	
	for(int i = 0; i < n; i++){
		cout << b[i] << " ";
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}