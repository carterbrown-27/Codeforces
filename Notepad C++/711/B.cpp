#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

#define pb push_back

void solve() {
	int n, W;
	cin >> n >> W;
	
	map<int,int> mp;
	int mx = 0;
	for(int i = 0; i < n; i++){
		int v;
		cin >> v;
		mp[v]++;
		mx = max(mx, v);
	}
	
	int ans = 0;
	while(true){
		int space = W;
		bool notEmp = false;
		// logn
		int k = mx;
		while(k > 0 && space > 0){
			if(mp[k]){
				notEmp = true;
				int times = min(mp[k], space/k);
				space -= times*k;
				mp[k] -= times;
			}
			k/=2;
		}
		if(!notEmp) break;
		ans++;
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