#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> g(m);
	
	for(int i = 0; i < n; i++){
		int v;
		cin >> v;
		g[v-1]++;
	}
	
	int p[m];
	for(int i = 0; i < m; i++){
		cin >> p[i];
	}
	
	ll sum = 0;
	int notTaken = 0;
	for(int i = m; i-- > 0;){
		while(g[i] > 0){
			if(notTaken < i){
				sum += p[notTaken++];
			}else{
				break;
			}
			g[i]--;
		}
		// cout << sum << " ";
		sum += p[i] * 1LL * g[i];
	}
	
	cout << sum << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}