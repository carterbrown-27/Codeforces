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
	
	if(n%2 == 0){
		cout << 2 << " " << n-3 << " " << 1 << endl;
	}else{
		bool kev = (n/2 % 2 == 1);
		cout << n/2 - 1 - kev << " " << n/2 + 1 + kev << " " << 1 << endl;
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