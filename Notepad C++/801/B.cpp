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
    
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    if(n%2 == 1){
        cout << "Mike" << endl;
        return;
    }
    
    int mn = 2e9;
    int mni = -1;
    for(int i = 0; i < n; i++){
        // whoever's min comes first loses
        if(a[i] < mn){
            mn = a[i];
            mni = i;
        }
    }
    
    cout << (mni%2 == 1 ? "Mike" : "Joe") << endl;
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