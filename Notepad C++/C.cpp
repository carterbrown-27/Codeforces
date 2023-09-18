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

#define FOR(i, l, r) for (int i = (l); (i) < (r); (i)++)
#define all(x) (x).begin(), (x).end()
#define pb push_back

bool solve() {
    string s;
    cin >> s;
    int m = s.length();
    
    // 0 = ?, 1=s, 2=(end of u)
    vector<int> v;
    int u_cnt = 0;
    int q_cnt = 0;
    for(char q: s){
        if(q=='+'){
            q_cnt++;
            v.push_back(0);
        }else if(q=='-'){
            int x = v.back();
            if(x == 0){
                q_cnt--;
            }else if(x == 2){
                u_cnt--;
            }
            v.pop_back();
        }else if(q=='1'){
            if(u_cnt > 0){
                return false;
            }
            q_cnt = 0;
            for(int i = v.size()-1; i >= 0 && v[i] == 0; i--){
                v[i] = 1;
            }
        }else if(q=='0'){
            if(v.size() < 2 || (q_cnt == 0 && u_cnt == 0)){
                return false;
            }
            
            if(v.back() != 2){
               q_cnt--;
               u_cnt++;
               v.back() = 2;  
            }
        }
    }
    
    return true;
}

int main() {
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cout << (solve() ? "YES" : "NO") << endl;
	}
	return 0;
}