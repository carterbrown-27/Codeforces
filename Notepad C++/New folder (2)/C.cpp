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
    int n;
    cin >> n;
    
    ll a[n], b[n];
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    
    int ans = 0;
    uset<ll> avail;
    
    // Worst-case = 200k*1k
    
    for(int i = 0; i < n; i++){
        uset<ll> common;
        for(auto& x: avail){
            if(x % b[i] == 0 && a[i] % (x/b[i]) == 0){
                common.insert(x);
            }
        }
        
        if(common.empty()){
            ans++;
            avail.clear();
            for(ll d = 1; d*d <= a[i]; d++){
                if(a[i] % d == 0){
                    avail.insert(d*b[i]);
                    avail.insert(a[i]/d * b[i]);
                }
            }
        }else{
            avail = common;
        }
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