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
	ll a, b;
	cin >> a >> b;
	
	if(b==1){
		cout << "NO" << endl;
	}else{
		cout << "YES" << endl;
		ll x = a*b, y = a;
		cout << x << " " << y << " " << x+y << endl;
	}
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