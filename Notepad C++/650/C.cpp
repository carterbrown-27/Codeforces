#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define push_back pb
#define make_pair mp

void solve() {
	int n,k;
	cin >> n >> k;
	
	string s;
	cin >> s;
	
	bool lg[n] {false};
	int d = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '1'){
			d = k;
		}else{
			lg[i] = (d-- <= 0);
		}
	}
	
	bool rg[n] {false};
	d = 0;
	for(int i = n-1; i >= 0; i--){
		if(s[i] == '1'){
			d = k;
		}else{
			rg[i] = (d-- <= 0);
		}
	}
	
	int ans = 0;
	d = 0;
	for(int i = 0; i < n; i++){
		if(lg[i] && rg[i]){
			if(d==0){
				ans++;
				d = k;
			}else{
				d--;
			}
		}else{
			d = 0;
		}
	}
	
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}