#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int n;
	cin >> n;
	
	vector<pair<int,int>> w;
	ll sum = 0;
	for(int i = 0; i < n; i++){
		int v;
		cin >> v;
		sum += v;
		w.pb(mp(v, i));
	}
	
	int d[n];
	memset(d, 0, sizeof(d));
	for(int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		d[u]++;
		d[v]++;
	}
	
	cout << sum << " ";
	sort(w.begin(), w.end(), greater<pair<int,int>>());
	
	for(int pos = 0; pos < w.size(); pos++){
		while(d[w[pos].second] > 1){
			// cout << w[pos].second << endl;
			sum += w[pos].first;
			d[w[pos].second]--;
			cout << sum << " ";
		}
	}
	cout << "\n";
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}