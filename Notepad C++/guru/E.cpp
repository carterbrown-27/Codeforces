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
    
    vector<string> ds(n);
    FOR(i, 0, n){
        cin >> ds[i];
    }
    
    int m;
    cin >> m;
    
    map<string, set<string>> mp;
    map<string, string> ans;
    
    vector<pair<string,string>> v;
    FOR(i, 0, m){
        string a,b;
        cin >> a >> b;
        v.pb({a,b});
    }
    
    for(auto& d : ds){
        set<string> possibles;
        set<string> hobbits;
        bool fresh = true;
        FOR(i, 0, m){
            auto [act,name] = v[i];
            // cout << act << " " << name << endl;
            if(act == "E"){
                hobbits.insert(name);
                if(ans.find(name) == ans.end()){
                    ans[name] = "???";
                }
            }else if(act == "L"){
                hobbits.erase(name);
            }else if(act == "M" && name == d){
                // set intersect 
                if(!possibles.empty()){
                    set<string> nP;
                    for(auto str: possibles){
                        if(hobbits.find(str) != hobbits.end()){
                            nP.insert(str);
                        }
                    }
                    possibles = nP;
                }else if(fresh){
                    fresh = false;
                    possibles = hobbits;
                }
            }
            
            mp[d] = possibles;
        }
    }
    
    bool changed = true;
    while(changed){
        changed = false;
        for(auto d: ds){
            auto st = mp[d];
            if(st.size() == 1){
                changed = true;
                auto hob = *st.begin();
                ans[hob] = d;
                for(auto o: ds){
                    mp[o].erase(hob);
                }
            }
        }
    }
    
    for(auto &p: ans){
        cout << p.first << ":" << p.second << endl;
    }
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}