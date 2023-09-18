#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct point {
	int x,y;
};

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
	int n;
    cin >> n;
    
    ll l, r;
    cin >> l >> r;
    
    ll m[n], b[n];
    for(int i = 0; i < n; i++){
        cin >> m[i] >> b[i];
    }
    
    vector<pair<ll,ll>> v;
    for(int i = 0; i < n; i++){
        v.pb({m[i]*l + b[i], m[i]*r + b[i]});
    }
    
    sort(v.begin(), v.end()); // lexi
    
    ll mxHi = v[0].second;
    ll curLo = v[0].first;
    for(int i = 1; i < n; i++){
        ll lo = v[i].first;
        ll hi = v[i].second;
        if(lo == curLo){
            mxHi = hi;
        }else if (hi >= mxHi){
            mxHi = hi;
            curLo = lo;
        }else{
            cout << "YES" << endl;
            return;
        }
    }
    
    cout << "NO" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}