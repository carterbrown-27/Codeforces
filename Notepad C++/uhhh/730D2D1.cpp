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
	int n, k;
	cin >> n >> k;
	
	for(int i = 0; i < n; i++){
		cout << (i > 0 ? (i-1)^i : 0) << endl;
		bool r;
		cin >> r;
		
		if(r){
			return;
		}
	}
}

int main() {
	// ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}