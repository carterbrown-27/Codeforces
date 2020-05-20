#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int a,b,c,n;
	cin >> a >> b >> c >> n;
	int mx = max(a, max(b,c));
	n -= mx*3 - (a+b+c);
	if(n>=0 && n%3==0){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
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