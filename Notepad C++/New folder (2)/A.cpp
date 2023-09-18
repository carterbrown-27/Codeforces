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

bool solve() {
    int n;
    cin >> n;
    
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    int b[n];
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    
    bool works = true;
    //try unswapped
    for(int i = 0; i < n-1; i++){
        if(!((a[i] <= a[n-1] && b[i] <= b[n-1]) || (a[i] <= b[n-1] && b[i] <= a[n-1]))){
            works = false;
        }
    }
    
    return works;
}

int main() {
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cout << (solve() ? "Yes" : "No") << endl;
	}
	return 0;
}