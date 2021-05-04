#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

#define pb push_back

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	
	ll g = 1;
	for(int i = 1; i < c; i++){
		g *= 10;
	}
	
	ll x = 1;
	for(int i = 1; i < max(a,b); i++){
		x *= 10;
	}
	
	ll y = 0;
	int m = g;
	for(int i = 0; i < min(a,b) - c + 1; i++){
		y += m*3;
		m*=10;
	}
	
	if(a < b){
		cout << y << " " << x << endl;
	}else{
		cout << x << " " << y << endl;
	}
	// cout << g << endl;
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