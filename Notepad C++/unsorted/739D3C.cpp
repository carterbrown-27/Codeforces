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
	
	int q = sqrt(n);
	
	if(q*q == n){
		cout << q << " " << 1 << endl;
		return;
	}
	
	int d = q+1;
	
	int dif = abs(q*q + d - n);
	
	int r = d-dif, c = d;
	if(n > q*q + d)
		swap(r,c);
	
	cout << r << " " << c << endl;
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