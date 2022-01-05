#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct point {
	int x,y;
};

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

template<typename T>
using uset = unordered_set<T>;

#define pb push_back

void solve() {
	int n;
	cin >> n;
	
	vector<bool> seen(n+1);
	vector<int> v;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(x <= n && !seen[x]){
			seen[x] = true;
		}else{
			v.pb(x);
		}
	}
	sort(v.begin(), v.end());
	
	auto vp = v.begin();
	
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(seen[i]) continue;
		
		if(*vp == i){
			++vp;
			continue;
		}else if((*vp+1)/2 > i){
			++vp;
			ans++;
		}else{
			cout << -1 << endl;
			return;
		}
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