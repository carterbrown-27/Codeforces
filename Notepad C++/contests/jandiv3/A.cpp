#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	long long n;
	cin >> n;
	while(n > 1){
		if(n%2 != 0){
			cout << "YES" << endl;
			return;
		}
		n/=2;
	}
	cout << "NO" << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}