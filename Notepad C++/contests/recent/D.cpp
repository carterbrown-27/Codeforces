#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> pll;
 
void solve() {
	int n,k;
	cin >> n >> k;
	int mn=1e9;
	for(int i = 1; i <= sqrt(n); i++){
		if(n%i==0){
			if(n/i<=k){
				mn = min(mn, i);
			}else if(i<=k){
				mn = min(mn, n/i);
			}
		}
	}
	cout << mn << endl;
}
 
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}