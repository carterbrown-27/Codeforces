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
    
    int odd = n%2;
    
    if(odd)
        cout << 1 << " ";
    
    for(int i = n-2; i >= 1+odd; i--){
        cout << i << " ";
    }
    
    cout << n-1 << " " << n << endl;
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