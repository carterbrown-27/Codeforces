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
	int n,k;
	cin >> n >> k;
	
	vector<int> a(n);
	for(int &x: a)
		cin >> x;
	
	map<int,vector<int>> t;
	
	for(int i = 0; i < n; i++)
		if(t[a[i]].size() < k)
			t[a[i]].pb(i);
	
	int unique = 0;
	for(auto &p: t){
		unique += p.second.size();
	}
	int coloured = (unique/k)*k;
	
	vector<int> ans(n, -1);
	vector<int> order;
	for(auto &p: t){
		order.insert(order.end(), p.second.begin(), p.second.end());
	}

	int c = 0;
	for(int i = 0; i < coloured; i++){
		ans[order[i]] = c++;
		c %= k;
	}
	
	for(int i = 0; i < n; i++)
		cout << ans[i] + 1 << " ";
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