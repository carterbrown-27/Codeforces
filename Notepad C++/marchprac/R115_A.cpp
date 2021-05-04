#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back

void solve() {
	int n;
	cin >> n;
	
	map<int,int> mp;
	for(int i = 1; i <= n; i++){
		cin >> mp[i];
	}
	
	map<int,int> dists;
	int mx = 0;
	for(int i = 1; i <= n; i++){
		int d = 0;
		int c = i;
		while(mp[c] != -1){
			if(dists.find(c) != dists.end()){
				d += dists[c];
				break;
			}
			d++;
			c = mp[c];
		}
		mx = max(d, mx);
		dists[i] = d;
	}
	
	cout << mx+1 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}