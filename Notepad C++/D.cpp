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

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	
	int de[n][m], re[n][m];
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m-1; j++)
			cin >> re[i][j];
	
	for(int i = 0; i < n-1; i++)
		for(int j = 0; j < m; j++)
			cin >> de[i][j];
		
	if(k&1){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cout << -1 << " ";
			cout << endl;
		}
		return;
	}
		
	int dp[n][m][k/2+1];
	memset(dp, 0, sizeof dp);
	
	const int MX = 1e9;
	
	for(int s = 1; s <= k/2; s++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				dp[i][j][s] = min({
					(i > 0 ? (dp[i-1][j][s-1] + de[i-1][j]) : MX),
					(j > 0 ? (dp[i][j-1][s-1] + re[i][j-1]) : MX),
					(i+1 < n ? (dp[i+1][j][s-1] + de[i][j]) : MX),
					(j+1 < m ? (dp[i][j+1][s-1] + re[i][j]) : MX)
				});
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			cout << dp[i][j][k/2] * 2 << " ";
		cout << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}