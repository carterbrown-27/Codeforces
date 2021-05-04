#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

#define pb push_back

void solve() {
	int n, m;
	
	cin >> n >> m;
	
	vector<string> board(n);
	for(int i = 0; i < n; i++){
		cin >> board[i];
	}
	
	if(n==1 && m == 1){
		cout << 0 << endl;
		return;
	}
	
	const int MOD = 998244353;
	const char W = 'o', B = '*';
	
	vector<vector<ll>> dp(n, vector<ll>(m));
	vector<vector<int>> hwh(n, vector<int>(m));
	vector<vector<int>> vwh(n, vector<int>(m));
	dp[0][0] = 0; // impl
	vwh[0][0] = hwh[0][0] = (board[0][0] == W);
	
	
	for(int i = 1; i < m; i++){
		dp[0][i] = dp[0][i-1];
		
		if(board[0][i] == W){
			// auto get
			dp[0][i] += hwh[0][i-1] * 2;
			// cout << hwh[0][i-1] << "w ";
			if(hwh[0][i-1] > 1){
				dp[0][i] += dp[0][i-2];
			}
			
			hwh[0][i] = max(1, hwh[0][i-1] * 2);
			hwh[0][i] %= MOD;
		}
		dp[0][i] %= MOD;
		cout << dp[0][i] << " ";
	}
	
	/*
	for(int i = 1; i < n; i++){
		for(int j = 1; j < n; j++){
			// do process
		}
	}
	*/
	
	cout << dp[n-1][m-1] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}