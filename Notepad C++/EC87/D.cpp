#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> ms;
	for(int i = 0; i < n; i++){
		int val;
		cin >> val;
		ms.push_back(val);
	}
	
	sort(ms.begin(),ms.end());
	
	for(int i = 0; i < q; i++){
		
	}
	
	cout << (ms.empty() ? 0 : *ms.begin()) << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}