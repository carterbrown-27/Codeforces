#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

#define pb push_back

void solve() {
	int n;
	cin >> n;
	
	int ans = 0;
	for(int i = 0; i < n; i++){
		int r;
		cin >> r;
		if(r == 1 || r == 3) ans++;
	}
	
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}