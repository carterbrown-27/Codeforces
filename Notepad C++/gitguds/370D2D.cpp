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
	
	int a, b, k, t;
	cin >> a >> b >> k >> t;
	
	const int MOD = 1e9 + 7;
	const int MXR = k*t*4 + max(a,b) + 1;
	// cout << MXR << endl;
	int z = MXR/2;
	
	vector<ll> dp(MXR);
	dp[a-b+z] = 1; // current difference is a-b
	
	vector<ll> tmp(MXR);
	for(int i = 0; i < t; i++){
		// rolling sum of range
		int ps = 0;
		for(int j = 0; j < MXR; j++){
			ps = (ps + dp[j]) % MOD;
			// exclude previous beginning
			if(j > 2*k)
				ps -= dp[j-(2*k+1)];
			// update center of range ending here
			if(j >= k)
				tmp[j-k] = ps % MOD;
		}
		dp = tmp;
		tmp.clear();
	}
	
	int sum = 0;
	for(int i = z+1; i < MXR; i++){
		sum = (sum + dp[i]) % MOD;
	}
	
	cout << sum << endl;
	return 0;
}