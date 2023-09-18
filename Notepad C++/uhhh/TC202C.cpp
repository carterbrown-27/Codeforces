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
	int n, p;
    cin >> n >> p;
    
    // k is at most 31:
    // any number x <= 2^31 = INT_MAX + 1 can obviously be represented by 31 bits
    for(int k = 1; k <= 31; k++){
        int x = n-k*p;
        int sb = 0;
        for(int t = x; t > 0; t /= 2)
            sb += t%2;
        
        if(sb > k){
            continue;
        // can do 0b10 -> 0?02 transforms to achieve every possible # of set bits
        // e.g. 2 = 0b10, but also 2 = 2^0 + 2^0.
        //      5 = 0b101, but also 5 = 2^1 + 2^1 + 2^0, 2^1 + 3*(2^0), 5*(2^0)
        }else if (k-sb <= x-1){
            cout << k << endl;
            return;
        }
    }
    
    cout << -1 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}