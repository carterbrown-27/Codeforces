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

void solve() {
    int n;
    cin >> n;
    
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    // try to make it <<<<< or >>>>>
    // pos/(lt/gt)
    int dp[n][2];
    dp[0][0] = dp[0][1] = 0;
    for(int i = 1; i < n; i++){
        if(a[i] > a[i-1]){
            dp[i][false] = dp[i-1][false] + 1;
            dp[i][true] = dp[i-1][true];
        }else if(a[i] < a[i-1]){
            dp[i][false] = dp[i-1][false];
            dp[i][true] = dp[i-1][true] + 1;
        }else{
            dp[i][false] = dp[i-1][false] + 1;
            dp[i][true] = dp[i-1][true] + 1;
        }
        
        dp[i][true] = min(dp[i][true], dp[i][false] + 1);
        dp[i][false] = min(dp[i][false], dp[i][true] + 1);
    }
    
    cout << dp[n-1][true] << endl;
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