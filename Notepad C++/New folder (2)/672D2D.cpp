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

#define MAXN 3e5+1
const int m = 998'244'353;
ll fact[MAXN];
ll inv_fact[MAXN];
ll inv[MAXN];


// event times =
// 0-open, 0-close, 1-open, 1-close, etc.

ll nCr(ll n, ll k, ll m){
    return fact[n] * inv_fact[k] % m * inv_fact[n-k] % m;
}

void prep(){
    fact[0] = 1;
    for(int i = 1; i <= MAXN; i++){
        fact[i] = fact[i-1]*i % m;
    }
    
    inv[1] = inv_fact[1] = 1;
    for(int i = 2; i <= MAXN; i++){
        inv[i] = m - (m/i) * inv[m%i] % m;
        inv_fact[i] = inv_fact[i-1] * inv[i];
    }
}

// editorial
// p(x) total passing thru
// s(x) those that start here
// new solutions from this point = (p(x) choose k) - (p(x)-s(x) choose k)

void solve() {
    int n, k;
    cin >> n >> k;
    
    // 2*n
    vector<pair<int,int>> segs;
    
    for(int i = 0; i < n; i++){
        int l,r;
        cin >> l >> r;
        segs.pb({l,1});
        segs.pb({r,-1});
    }
    
	// pickup array
    sort(segs.begin(), segs.end());
    
    int c = 0;
    for(int i = 0; i < segs.size(); i++){
        const auto& [pos, d]: segs[i];
        
        // only want to handle opens?
        while(i < segs.size() && segs[i].first == pos){
            c += segs[i].second;
            i++;
        }
        
        if(c >= k){
            
        }
    }
    // n choose k
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}