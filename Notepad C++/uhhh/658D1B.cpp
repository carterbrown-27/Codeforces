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
	
	vector<int> p(2*n);
	for(int &x: p)
		cin >> x;

	const int A = 0, B = 1;
	bool dp[2][2*n][2*n+1];
	memset(dp, false, sizeof dp);
	
	// put p_0 in a
	dp[A][0][p[0]] = true;
	for(int i = 1; i < 2*n; i++){
		int x = p[i];
		for(int j = 1; j < x; j++){
			if(dp[A][i-1][j]){
				dp[A][i][x] = true;
				break;
			}
		}
		// idk
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