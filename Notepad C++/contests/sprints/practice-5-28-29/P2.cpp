#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int n;
	cin >> n;
	int b[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &b[i]);
	}
	
	// removed uneccessary loop & array
	
	map<int,ll> sums;
	for(int i = 0; i < n; i++){
		sums[(i+1) - b[i]]+=b[i];
	}
	
	ll mx = 0;
	for(auto const &p: sums){
		mx = max(mx,p.second);
	}
	
	cout << mx << endl;
}

int main() {
	solve();
	return 0;
}