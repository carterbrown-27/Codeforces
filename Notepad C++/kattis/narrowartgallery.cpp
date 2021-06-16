#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

template<typename T>
using uset = unordered_set<T>;

#define pb push_back

int main() {
	ios::sync_with_stdio(false);
	
	int n, k;
	cin >> n >> k;
	
	enum side {C_L, C_R, C_N};
	
	int a[n+1][2];
	for(int i = 0; i <= n; i++){
		cin >> a[i][C_L] >> a[i][C_R];
	}
	
	// pos, closed count, prev side
	int dp[n][k+1][3];
	memset(dp, 0x3f, sizeof dp);
	dp[0][0][C_N] = 0;
	dp[0][1][C_L] = a[0][C_L];
	dp[0][1][C_R] = a[0][C_R];
	
	for(int i = 1; i < n; i++){
		for(int c = 0; c <= k; c++){
			dp[i][c][C_N] = min({dp[i-1][c][C_N], dp[i-1][c][C_L], dp[i-1][c][C_R]});
			if(c > 0){
				int pn = dp[i-1][c-1][C_N];
				dp[i][c][C_L] = min(pn, dp[i-1][c-1][C_L]) + a[i][C_L];
				dp[i][c][C_R] = min(pn, dp[i-1][c-1][C_R]) + a[i][C_R];
			}
		}
	}
	
	int mn = 1e9;
	for(int i = 0; i < n; i++){
		for(int p = 0; p < 3; p++){
			mn = min(mn, dp[i][k][p]);
		}
	}
	
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += a[i][C_L] + a[i][C_R];
	}
	
	cout << sum - mn << endl;
	
	return 0;
}