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
    
    int a[n], b[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    for(int i = 0; i < n; i++)
        cin >> b[i];
    
    umap<int,int> amp;
    for(int i = 0; i < n; i++){
        amp[a[i]]++;
    }
    
    // handle matches
    umap<int,int> bmp;
    for(int i = 0; i < n; i++){
        if(amp[b[i]] > 0){
            --amp[b[i]];
        }else{
            ++bmp[b[i]];
        }
    }
    
    auto dl = [](int n) -> int{
        ll t = 1;
        int c = 1;
        while(t*10 <= n){
            t*=10;
            c++;
        }
        return c;
    };
    
    
    int ans = 0;
    vector<int> ads(10), bds(10);
    for(auto& [k,v]: amp)
        if(v > 0){
            if(k >= 10){
                ads[dl(k)] += v;
                ans += v;
            }else{
                ads[k] += v;
            }
        }
        
    for(auto& [k,v]: bmp)
        if(v > 0){
            if(k >= 10){
                bds[dl(k)] += v;
                ans += v;
            }else{
                bds[k] += v;
            }
        }  
    
    for(int i = 1; i <= 9; i++){
        // cout << ads[i] << " " << bds[i] << endl;
        int mn = min(ads[i], bds[i]);
        
        if(i>1){
            ans += max(ads[i], bds[i]) - mn;
            // cout << i << ": " << ans << endl;
        }
        
        ads[i] -= mn;
        bds[i] -= mn;
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