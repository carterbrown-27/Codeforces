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

const int INF = 1e4;

short dp[801][401][101];

short dfs(int n1, int n5, int n10, int c, int k)
{	
	if(n1 < 0 || n5 < 0 || n10 < 0 || c > k) return INF;
	if(c == k) return 0;
	if(dp[n1][n5][n10] != -1) return dp[n1][n5][n10];
	
	return dp[n1][n5][n10] = min({
		dfs(n1-8, n5, n10, c+1, k) + 8,
		dfs(n1-3, n5+1, n10-1, c+1, k) + 4,
		dfs(n1-3, n5-1, n10, c+1, k) + 4,
		dfs(n1+2, n5-2, n10, c+1, k) + 2,
		dfs(n1+2, n5, n10-1, c+1, k) + 1
	});
}

void solve() {
	int C, n1, n5, n10;
	cin >> C >> n1 >> n5 >> n10;
	
	int mx1 = n1 + 2*C, mx5 = n5 + 2*C;

	for(int i = 0; i <= mx1; i++)
		for(int j = 0; j <= mx5; j++)
			for(int k = 0; k <= n10; k++)
				dp[i][j][k] = -1;
			
	cout << dfs(n1, n5, n10, 0, C) << endl;
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