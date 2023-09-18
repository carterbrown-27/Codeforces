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
	
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	int mn = a[0];
	for(int i = 1; i < n; i++){
		if(int d = a[i-1]-a[i]; d > 0){
			if(mn >= d){
				mn -= d;
			}else{
				cout << "NO" << endl;
				return;
			}
		}
		mn = min(mn, a[i]);
	}
	cout << "YES" << endl;
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