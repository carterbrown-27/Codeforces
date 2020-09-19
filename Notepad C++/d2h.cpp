#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

ll dp[21][21];

ll solve(int x, int y) {
	if(dp[x][y] != -1) return dp[x][y];
	return dp[x][y] = ((x > 1 ? solve(x-1, y) : 0) + (y > 1 ? solve(x, y-1) : 0));
}

int main() {
	memset(dp, -1, sizeof(dp));
	const int N = 20;
	for(int i = 1; i <= N; i++){
		dp[i][1] = dp[1][i] = i+1;
	}
	solve(N,N);
	for(int i = 1; i <= N; i++){
		cout << dp[i][i] << " ";
	}
	cout << endl;
	// 137846528820
	return 0;
}