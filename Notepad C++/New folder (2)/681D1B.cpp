#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct point {
	int x,y;
};

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template<typename T, typename U>
using umap = unordered_map<T,U,custom_hash>;

template<typename T>
using uset = unordered_set<T,custom_hash>;

#define pb push_back

void solve() {
    int n, k;
    cin >> n >> k;
    
    int a[n];
    umap<int, int> aIdx;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        aIdx[a[i]] = i;
    }
    
    int b[k];
    int bPos[k];
    vector<bool> isX(n, true);
    for(int i = 0; i < k; i++){
        cin >> b[i];
        bPos[i] = aIdx[b[i]];
        isX[bPos[i]] = false;
    }
    
    const ll MOD = 998'244'353;
    ll ans = 1;
    for(int i = 0; i < k; i++){
        int j = bPos[i];
        int m = (j > 0 && isX[j-1]) + (j < n-1 && isX[j+1]);
        
        ans = ans * m % MOD;
        
        isX[j] = true;
    }
    
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