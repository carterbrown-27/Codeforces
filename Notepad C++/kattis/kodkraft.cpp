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

ll dfs(int n, int k, int* a, ll* dp, int pos, vector<set<int>>& non){
	if(dp[pos] != -1) return dp[pos];
	if(a[pos] == k) return dp[pos] = 1;
	
	int npos = *(non[a[pos]+1].upper_bound(pos));
	return dp[pos] = dfs(n, k, a, dp, npos%n, non) + (npos-pos);
}

int main() {
	ios::sync_with_stdio(false);
	
	int n, k;
	cin >> n >> k;
	
	// next of number
	vector<set<int>> non(k+1);
	int a[n];
	
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		a[i] = x;
		non[x].insert(i);
		non[x].insert(n + i); // next year
	}
	
	ll dp[n];
	for(int i = 0; i < n; i++)
		dp[i] = -1;
	
	
	ll mn = 1e12;
	for(int i = 0; i < n; i++){
		dfs(n, k, a, dp, i, non);
		if(a[i] == 1) mn = min(mn, dp[i]);
		// cout << dp[i] << " ";
	}
	// cout << "\n";
	
	cout << mn << endl;
	
	return 0;
}