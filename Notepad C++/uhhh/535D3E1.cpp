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
	int n, m;
	cin >> n >> m;
	
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	vector<vector<int>> Ls(n);
	vector<vector<int>> Rs(n);
	for(int j = 0; j < m; j++){
		int l,r;
		cin >> l >> r;
		l--, r--;
		Ls[l].pb(j);
		if(r+1 < n)
			Rs[r+1].pb(j);
	}
	
	int d = 0;
	vector<int> c;
	// search all [l,r)
	for(int r = 0; r <= n; r++){
		for(int l = 0; l < r; l++){
			// cout << l << " " << r << " = ";
			// apply all segs within [l,r)
			uset<int> curs;
			vector<int> used;
			int mx = -1e6, mn = 1e6;
			for(int i = 0; i < n; i++){
				// within [l,r]
				if(l <= i && i < r){
					for(int x: Ls[i]){
						curs.insert(x);
						used.pb(x);
					}
				}
				for(int x: Rs[i])
					if(curs.find(x) != curs.end())
						curs.erase(x);
				int v = a[i] - curs.size();
				mx = max(mx, v);
				mn = min(mn, v);
			}
			if(mx-mn > d){
				d = mx-mn;
				c = used;
			}
			// cout << mx << " - " << mn << " = " << d << endl;
		}
	}
	
	cout << d << endl;
	cout << c.size() << endl;
	for(int x : c)
		cout << x+1 << " ";
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}