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
    
    vector<vector<int>> p(n, vector<int>(m));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> p[i][j];
	
	auto f = [&] (int x) -> bool {
		vector<bool> b(m);
		bool share_shop = false;
		for(int i = 0; i < n; i++){
			int c = 0;
			for(int j = 0; j < m; j++){
				if(p[i][j] >= x){
					b[j] = true;
					c++;
				}
			}
			if(c >= 2)
				share_shop = true;
		}
		
		for(bool o: b)
			if(!o)
				return false;
		
		return share_shop;
	};
	
	int l = 1, r = 1e9;
	while(l <= r){
		int mid = (l+r)/2;
		if(f(mid)){
			l = mid+1;
		}else{
			r = mid-1;
		}
	}
	
	cout << l-1 << endl;
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