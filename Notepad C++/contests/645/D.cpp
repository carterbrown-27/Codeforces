#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

ll sigma(ll n){
	return n*(n+1)/2;
}

void solve() {
	int n,x;
	cin >> n >> x;
	int d[n];
	
	for(int i = 0; i < n; i++){
		scanf("%d", &d[i]);
	}
	
	ll mx = 0;
	for(int i = 0; i < n; i++){
		// start at end of ith month
		int tx = x;
		ll sum = 0;
		for(int j = i;; j--){
			if(j==-1) j=n-1;
			sum+=sigma(d[j]);
			if(d[j] >= tx){
				sum-=sigma(d[j]-tx);
				break;
			}
			
			tx-=d[j];
		}
		mx = max(mx, sum);
	}
	
	cout << mx << endl;
}

int main() {
	solve();
	return 0;
}