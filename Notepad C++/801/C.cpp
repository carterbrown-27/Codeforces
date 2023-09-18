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
    
    int a[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    
    int lop = n+m-1;
    if(lop%2 != 0){
        cout << "NO" << endl;
        return;
    }
    
    int dp[n][m];
    dp[n-1][m-1] = (a[n-1][m-1] == -1);
    for(int i = n-1; i-- > 0;){
        for(int j = m-1; j-- > 0;){
            // what
            dp[i][j] = max(dp[i+1][j], dp[i][j+1]) + (a[i][j] == -1);
        }
    }
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
}