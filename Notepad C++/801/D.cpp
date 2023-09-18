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
    
    vector<int> fr(n+1);
    for(int i = 0; i < n-1; i++){
        int x,y;
        cin >> x >> y;
        fr[x]++;
        fr[y]++;
    }
    
    if(n <= 2){
        cout << n-1 << endl;
        return;
    }
    
    int mx = 0;
    for(int deg: fr){
        mx = max(mx, deg);
    }
    
    cout << mx-1 << endl;
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