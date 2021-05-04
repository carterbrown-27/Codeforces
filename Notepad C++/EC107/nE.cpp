#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

#define pb push_back

int dfs(vector<vector<int>>& ans, vector<string>& b, int x, int y, bool v){
	if(y >= b.size() || x >= b[y].size()) return 0;
	if(b[y][x] == '*') return 0;
	
	ans[y][x] += dfs(ans, b, x, y+1, true) + v;
	ans[y][x] += dfs(ans, b, x+1, y, false) + !v;
	
	return ans[y][x];
}

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
	
	vector<vector<int>> ans(n, vector<int>(m));
	dfs(ans, board, 0, 0, true);
	dfs(ans, board, 0, 0, false);
	
	cout << ans[0][0] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}