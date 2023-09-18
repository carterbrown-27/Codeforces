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
	int m;
    cin >> m;
    
    int n;
    cin >> n;
    
    map<char,set<char>> mp;
    
    FOR(i, 0, m){
        char a, b;
        cin >> a >> b;
        mp[a].insert(b);
        //dsu.uni(a-'a',b-'a');
    }
    
    for(char ca = 'a'; ca <= 'z'; ca++){
        set<char> seen;
        int sz = 0;
        seen.insert(ca);
        while(sz != seen.size()){
            sz = seen.size();
            set<char> newSeen = seen;
            for(char c: seen){
                for(char d: mp[c]){
                    newSeen.insert(d);
                }
            }
            seen = newSeen;
        }
        mp[ca] = seen;
    }
    
    FOR(i, 0, n){
        string a, b;
        cin >> a >> b;
        if(a.length() != b.length()){
             cout << "no" << endl;
             continue;
        }
        
        int l = a.length();
        bool works = true;
        FOR(j, 0, l){
            char ca = a[j], cb = b[j];
            auto st = mp[ca];
            if(st.find(cb) == st.end()){
                works = false;
                break;
            }
        }
        cout << (works ? "yes" : "no") << endl; 
    }
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}