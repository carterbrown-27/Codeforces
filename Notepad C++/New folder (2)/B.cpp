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
    int m;
    cin >> m;
    
    umap<int,int> last;
    for(int i = 0; i < m; i++){
        int n;
        cin >> n;
        
        for(int j = 0; j < n; j++){
            int p;
            cin >> p;
            last[p] = i;
        }
    }
    
    vector<int> picks(m, -1);
    for(auto& [k,day]: last){
        picks[day] = k;
    }
    
    vector<int> ans;
    for(int i = 0; i < m; i++){
        if(picks[i] == -1){
            cout << "-1" << endl;
            return;
        }
        ans.pb(picks[i]);
    }
    
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