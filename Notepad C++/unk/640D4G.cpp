#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct point {
	int x,y;
};

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

template<typename T>
using uset = unordered_set<T>;

#define pb push_back

void solve() {
	int n;
	cin >> n;
	
	if(n < 4){
		cout << -1 << endl;
		return;
	}
	
	vector<int> ans;
	int i;
	for(i = 2; i <= n; i+=2)
		ans.pb(i);
	i-=2;
	
	for(i = i-3; i >= 1; i-=4)
		ans.pb(i);
	
	for(i = (ans[ans.size()-1] == 1) ? 3 : 1; i <= n; i+=4)
		ans.pb(i);
	
	if(ans.size() < n)
		ans.pb(n);
	
	for(int x: ans)
		cout << x << " ";
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}