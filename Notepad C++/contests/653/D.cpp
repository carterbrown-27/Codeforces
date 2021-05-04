#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int n,k;
	cin >> n >> k;
	map<int,int> m;
	for(int i = 0; i < n; i++){
		int v;
		cin >> v;
		int mod = (k-(v%k))%k;
		m[mod]++;
	}
	
	int mx = 0;
	int mxi = 0;
	for(auto const &p: m){
		if(p.first == 0) continue;
		if(p.second >= mx && p.first > mxi){
			mx = p.second;
			mxi = p.first;
		}
	}
	
	if(mx == 0){
		cout << 0 << endl;
	}else{
		cout << (1ll*(mx-1)*k + mxi) + 1 << endl;
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