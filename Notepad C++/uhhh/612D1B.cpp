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
    
    vector<vector<int>> chln(n+1);
    int c[n]
    for(int i = 1; i <= n; i++){
        int p, ci;
        cin >> p >> ci;
        chln[p].pb(i);
        c[i-1] = ci;
    }
    
    // tree -> always DAG (even when undir->dir w/ arb directions: no back-edges possible)
    // always possible if c_i <= size of subtree rooted at i, - 1 ??
    vector<vector<int>> adj(n+1);
    for(int i = 0; i <= n; i++){
        const auto &v = chln[i];
        int s = 0;
        for(int j: v){
            s += c[j-1];
        }
        
        
    }
    
    
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}