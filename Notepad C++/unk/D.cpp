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
	int n, m, k;
	cin >> n >> m >> k;
	
	int A = 2*k;
	
	for(int w = 0; w <= m; w+=2){
		for(int h = 0; h <= n && h*w <= A; h++){
			// valid rectangle
			if(h*w == A){
				if(((h > 0 && w == m) || n%2 == 0) && (n-h)%2 == 0){
					cout << "YES" << endl;
					return;
				}
			}
		}
	}
	
	cout << "NO" << endl;
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