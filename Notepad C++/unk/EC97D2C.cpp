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
	
	vector<int> a(n);
	for(int &x: a)
		cin >> x;
	
	sort(a.begin(), a.end());
	
	const int MAX = 1e8;
	const int MXM = 2*n;
	
	int dp[MXM+1][n+1];	
	for(int i = 0; i <= MXM; i++)
		for(int j = 0; j <= n; j++)
			dp[i][j] = MAX;
		
	dp[0][0] = 0;
	
	for(int i = 1; i <= MXM; i++){
		for(int j = 0; j <= n; j++){
			dp[i][j] = min(
				dp[i-1][j],
				j > 0 ? (dp[i-1][j-1] + abs(a[j-1] - i)) : MAX
			);
		}
	}
	
	int mn = MAX;
	for(int i = 1; i <= MXM; i++)
		mn = min(mn, dp[i][n]);
	
	cout << mn << endl;
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