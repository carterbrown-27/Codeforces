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
    
    int mx = -2e9;
    int mxi, mxj;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int v;
            cin >> v;
            if(v > mx){
                mx = v;
                mxi = i;
                mxj = j;
            }
        }
    }
    
    int ans = (n-min(n-mxi-1, mxi)) * (m-min(m-mxj-1, mxj));
    cout << ans << endl;
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