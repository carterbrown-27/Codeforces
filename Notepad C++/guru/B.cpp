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

#define FOR(i, l, r) for (int i = (l); (i) < (r); (i)++)
#define all(x) (x).begin(), (x).end()
#define pb push_back

void solve() {
	int n;
    cin >> n;
    
    string tmp;
    getline(cin, tmp);
    
    string s;
    getline(cin, s);
    
    cout << s.length() << endl;
    int m = s.length();
    
    vector<int> ans(m*10, -1);
    vector<int> d(m*10);
    for(int i = 0; i < m; i++){
        ans[i] = s[i];
    }
    
    FOR(i, 0, n){
        int l, r;
        cin >> l >> r;
        
        getline(cin, tmp);
        
        string t;
        getline(cin, t);
        
        // cout << t.length()) << endl;
        
        int adj = 0;
        for(int i = 0; i < l; i++){
            adj += d[i];
        }
        
        int len = r-l;
        int m = t.length();
        for(int j = 0; j < max(len,m); j++){
            int nv = (j < m ? t[j] : -1);
            
            int idx = l+j+adj;
            ans[idx] = nv;
            adj += d[i];
            if(nv == -1){
                d[idx]++;
            }else if (j >= len){
                d[idx]--;
            }
            
        }
    }
    
    string out;
    
    for(int x: ans){
        if(x != -1){
            out += (char) x;
        }
    }
    
    cout << out << endl;
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}