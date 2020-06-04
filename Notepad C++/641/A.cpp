#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int n, k;
	cin >> n >> k;
	int low = n;
	
	// if n is even, low = 2. n + low = even + even = even
	// if n is odd, low = odd. n + low = odd + odd = even, return to case 1.
	for(int i = 2; i*i <= n; i++){
		if(n%i==0){
			low = i;
			break;
		}
	}
	
	cout << (2*(k-1) + n + low) << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}