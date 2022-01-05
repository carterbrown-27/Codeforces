#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using uset = unordered_set<T>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

#define pb push_back

void solve() {
	int n;
	cin >> n;
	
	string as, bs;
	cin >> as >> bs;
	
	int a[n], b[n];
	for(int i = 0; i < n; i++){
		a[i] = as[i] - '0';
		b[i] = bs[i] - '0';
	}
	
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(b[i] == 0) continue;
		if(i > 0 && a[i-1] == 1){
			ans++;
			a[i-1] = 2; // to be safe
		}else if(a[i] == 0){
			ans++;
			a[i] = 2;
		}else if(i < n-1 && a[i+1] == 1){
			ans++;
			a[i+1] = 2;
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