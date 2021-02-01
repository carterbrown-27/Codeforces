#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	set<int> diffs;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			diffs.insert(a[i]-a[j]);
		}
	}
	
	cout << diffs.size() << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}