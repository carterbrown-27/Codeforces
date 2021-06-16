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
	const int MX = 0x3f3f3f3f;
	
	int m, S;
	cin >> m >> S;
	
	int coins[m][2];
	for(int i = 0; i < m; i++)
		cin >> coins[i][0] >> coins[i][1];
	
	int best[S+1][S+1];
	memset(best, 0x3f, sizeof best);
	best[0][0] = 0;
	
	
	// O(m * S^2)
	for(auto coin: coins)
		for(int c = coin[0]; c <= S; c++)
			for(int t = coin[1]; t <= S; t++)
				best[c][t] = min(best[c][t], best[c-coin[0]][t-coin[1]] + 1);

	int mn = MX;
	
	for(int t = 0; t <= S; t++){
		int d = S*S - t*t;
		int c = sqrt(d);
		if(c*c == d)
			mn = min(mn, best[c][t]);
	}
	
	if(mn < MX){
		cout << mn << endl;
	}else{
		cout << "not possible" << endl;
	}
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