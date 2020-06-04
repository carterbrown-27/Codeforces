#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int x,y,a,b;
	cin >> x >> y >> a >> b;
	
	int num = y-x;
	int den = a+b;
	if(num%den == 0){
		cout << num/den << endl;
	}else{
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