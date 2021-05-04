#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int n;
	cin >> n;
	map<int,int> mp;
	for(int i = 0; i < n; i++){
		int v;
		cin >> v;
		mp[v]++;
	}
	
	int mx = 0;
	for(auto const &p: mp){
		mx = max(mx, p.second);
	}
	
	cout << mx << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}