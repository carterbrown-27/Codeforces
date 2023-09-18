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
    
    int w, m;
    cin >> w >> m;
    
    int a[n];
    for(int i = 0; i < n; i++)
        a[i] = s[i]-'0';
    
    int prf[n+1];
    prf[0] = 0;
    for(int i = 1; i <= n; i++)
        prf[i] = prf[i-1] + a[i-1];
    
    vector<vector<int>> mds(9);
    for(int i = 0; i <= n-w; i++){
        int x = (prf[i+w]-prf[i])%9;
        mds[x].pb(i+1);
        // cout << i << " " << x << endl;
    }
    
    for(int q = 0; q < m; q++){
        int l,r,k;
        cin >> l >> r >> k;
        int alph = (prf[r]-prf[l-1])%9;
        
        int mn1 = n+1, mn2 = n+1;
        for(int j = 0; j < 9; j++){
            if(mds[j].empty()) continue;
            for(int b = 0; b < 9; b++){ 
                if(mds[b].empty()) continue;
                if(j == b && mds[b].size() < 2) continue;
                
                if((j*alph)%9 == ((k-b)%9 + 9)%9){
                    int c, d;
                    if(j == b){
                        c = mds[j][0];
                        d = mds[j][1];
                    }else{
                        c = mds[j][0];
                        d = mds[b][0];
                    }
                    
                    if(c < mn1){
                        mn1 = c;
                        mn2 = d;
                    }else if(c == mn1 && d < mn2){
                        mn2 = d;
                    }
                }
            }
        }
        
        if(mn1 == n+1){
            cout << -1 << " " << -1 << endl;
        }else{
            cout << mn1 << " " << mn2 << endl;
        }
    }
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