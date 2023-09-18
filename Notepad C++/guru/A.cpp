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

string solve() {
	int n;
    cin >> n;
    
    int T = n*2;
    string frags[T];
    FOR(i, 0, T) {
      cin >> frags[i];  
      // cout << frags[i] << endl;
    }
    
    int tlen = 0;
    map<int, uset<int>> mp;
    FOR(i, 0, T) {
        tlen += frags[i].length();
        mp[frags[i].length()].insert(i);
    }
    
    int L = tlen / n;
    umap<int, int> freq;
    FOR(i, 0, T){
       freq[frags[i].length()]++;
    }
    
    for(auto &[s,f]: freq){
        if(freq.find(L-s) == freq.end()){
            // cout << s << endl;
            return "Impossible";
        }
        
        if(freq[L-s] != f){
            return "Impossible";
        }
    }
    
    set<string> poss;
    string a = frags[0];
    FOR(i, 1, T){
        string b = frags[i];
        if(a.length() + b.length() == L){
            // generate possibilites.
            poss.insert(a + b);
            poss.insert(b + a);
            if(poss.size() > 4){
                return "Impossible";
            }
        }
    }
    
    for(string p: poss){
        bool works = true;
        FOR(i, 0, T){
            string f = frags[i];
            if(!(p.substr(0,f.length()) == f || f == p.substr(p.length()-f.length()))){
                works = false;
            }
        }
        
        if(works){
            return p;
        }
    }
    
    return "Impossible";
}

int main() {
	ios::sync_with_stdio(false);
	cout << solve() << endl;
	return 0;
}