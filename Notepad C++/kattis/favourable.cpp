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

const int N = 401;
ll dp[N];

ll dfs(vector<vector<int>>& edges, int p){
	// cout << p << endl;
	if(dp[p] != -1) return dp[p];
	
	ll ans = 0;
	for(int v: edges[p]){
		ans += dfs(edges, v);
	}
	
	return dp[p] = ans;
}

void solve() {
	int n;
	cin >> n;
	
	for(int i = 0; i < N; i++){
		dp[i] = -1;
	}
	
	vector<vector<int>> edges(N);
	
	for(int i = 0; i < n; i++){
		int p;
		string s;
		cin >> p >> s;
		
		if(s[0] == 'f'){
			dp[p] = 1;
		}else if(s[0] != 'c'){
			int a = stoi(s);
			int b,c;
			cin >> b >> c;
			
			edges[p].pb(a);
			edges[p].pb(b);
			edges[p].pb(c);
		}
	}
	
	cout << dfs(edges, 1) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}