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
    
    int c[n];
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    
    int mxi = 0;
    for(int i = 1; i < n; i++){
        if(c[i] > c[mxi])
            mxi = i;
    }
    
    cout << mxi+1 << endl;
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