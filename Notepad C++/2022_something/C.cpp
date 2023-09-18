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
    string s;
    cin >> s;
    
    int n = s.length();
    
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        a[i] = (s[i]-'a'+1);
    }
    
    int cost = abs(a[0]-a[n-1]);
    int mn = min(a[0], a[n-1]);
    int mx = max(a[0], a[n-1]);
    
    umap<int,vector<int>> ind;
    for(int i = 1; i < n-1; i++){
        ind[a[i]].pb(i+1);
    }
    
    vector<int> ans;
    ans.pb(1);
    if(a[0] <= a[n-1]){
        for(int i = mn; i <= mx; i++){
            if(ind.find(i) != ind.end())
                for(auto& x: ind[i])
                    ans.pb(x);
        }
    }else{
        for(int i = mx; i >= mn; i--){
            if(ind.find(i) != ind.end())
                for(auto& x: ind[i])
                    ans.pb(x);
        }
    }
    
    ans.pb(n);
    
    cout << cost << " " << ans.size() << endl;
    for(auto& x: ans){
        cout << x << " ";
    }
    cout << endl;
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