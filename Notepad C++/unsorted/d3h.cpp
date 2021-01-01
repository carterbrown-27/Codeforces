#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

const int N = 16;
// dp[pos][has 0][has 1][has A]
ll dp[N][2][2][2];
ll solve(int pos, bool z, bool o, bool a) {
	if(pos == N) return z && o && a;
	if(dp[pos][z][o][a] != -1) return dp[pos][z][o][a];
	
	// try every digit
	ll total = z && o && a;
	for(int i = (pos==0); i <= 2; i++){
		total += solve(pos+1, z | i == 0, o | i == 1, a | i == 2);
	}
	total += 13*solve(pos+1, z, o, a);
	
	return dp[pos][z][o][a] = total;
}

int main() {
	memset(dp, -1, sizeof(dp));
	solve(0,0,0,0);
	
	cout << hex <<  dp[0][0][0][0] << endl;
	cout << dp[0][0][0][0] << endl;
	// 3D58725572C62302
	return 0;
}