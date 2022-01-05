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
	
	int n, m, K;
	cin >> n >> m >> K;
	
	int c[n];
	for(int i = 0; i < n; i++)
		cin >> c[i];
	
	int p[n][m];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> p[i][j];
		
	// cost of (pos, segs) ending with colour
	const ll MAX = 1e18;
	ll dp[n][K+1][m];
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j <= K; j++)
			for(int k = 0; k < m; k++)
				dp[i][j][k] = MAX;
			
	if(c[0] == 0){
		for(int k = 0; k < m; k++)
			dp[0][1][k] = p[0][k];
	}else{
		dp[0][1][c[0]-1] = 0;
	}
	
	for(int i = 1; i < n; i++){
		for(int j = 1; j <= K; j++){
			if(c[i] == 0){
				for(int k = 0; k < m; k++)
					for(int pc = 0; pc < m; pc++)
						dp[i][j][k] = min(dp[i][j][k], dp[i-1][pc == k ? j : j-1][pc] + p[i][k]);
			}else{
				int cur = c[i]-1;
				for(int pc = 0; pc < m; pc++)
					dp[i][j][cur] = min(dp[i][j][cur], dp[i-1][pc == cur ? j : j-1][pc]);
			}
		}
	}
	
	/*
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= K; j++){
			for(int k = 0; k < m; k++){
				cout << dp[i][j][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	*/
	
	ll mn = MAX;
	for(int pc = 0; pc < m; pc++)
		mn = min(mn, dp[n-1][K][pc]);
		
	cout << (mn == MAX ? -1 : mn) << endl;
	return 0;
}