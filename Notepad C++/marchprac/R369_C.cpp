#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

unordered_map<int, unordered_map<int,bool>> w;
vector<int> ans;

bool dfs(int x, int p, bool b){
	// cout << x << " " << p << " " << b << endl;
	bool choseChild = false;
	for(auto const &kv: w[x]){
		int v = kv.first;
		if(v != p){
			choseChild |= dfs(v, x, kv.second);
		} 
	}
	if(b && !choseChild){
		ans.pb(x);
		return true;
	}
	
	return choseChild;
}

void solve() {
	int n;
	cin >> n;

	for(int i = 0; i < n-1; i++){
		int x,y,t;
		cin >> x >> y >> t;
		x--, y--, t--;
		w[x][y] = t;
		w[y][x] = t;
	}
	
	dfs(0, -1, false);
	
	cout << ans.size() << endl;
	for(int x: ans){
		cout << x+1 << " ";
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}