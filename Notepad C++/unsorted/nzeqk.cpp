#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

vector<int> num;
int dp[100][100][2];
int k;
const int MOD = 1e9 + 7;

int solve(int pos, int c, bool isLess){
	if(c > k) return 0;
	if(pos >= num.size()) return c == k;
	if(dp[pos][c][isLess] != -1) return dp[pos][c][isLess];
	
	int mx = isLess ? 9 : num[pos];
	
	int sum = 0;
	for(int d = 0; d <= mx; d++){
		sum = (sum + solve(pos+1, c + (d != 0), isLess | d < mx)) % MOD;
	}
	
	return dp[pos][c][isLess] = sum % MOD;
}

int ans(string n){
	num.clear();
	for(char c: n){
		num.push_back(c-'0');
	}
	
	memset(dp, -1, sizeof(dp));
	return solve(0, 0, false);
}

int main() {
	string l, r;
	cin >> l >> r >> k;
	cout << (ans(r) - ans(l) + MOD) % MOD << endl;
	return 0;
}