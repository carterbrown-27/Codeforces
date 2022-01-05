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
	int n, m;
	cin >> n >> m;
	
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	if(n > m){
		cout << 0 << endl;
		return;
	}
	
	ll res = 1;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			res = (res * abs(a[i]-a[j])) % m;
		}
	}
	
	cout << res << endl;
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}