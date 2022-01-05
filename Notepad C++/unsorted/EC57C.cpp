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
	int ang;
	cin >> ang;
	
	int g = __gcd(ang, 180);
	int n = 180 / g;
	if(ang / g >= n-1)
		n *= 2;
	
	cout << n << endl;
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