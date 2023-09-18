#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct point {
	int x,y;
};

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

template<typename T>
using uset = unordered_set<T>;

#define pb push_back

bool solve() {
	int n;
    cin >> n;
    
    vector<int> freq(n);
    for(int i = 0; i < n-1; i++){
        int u,v;
        cin >> u >> v;
        --u, --v;
        ++freq[u], ++freq[v];
    }
    
    for(int i = 0; i < n; i++){
        if(freq[i] == 2){
            return false;
        }
    }
    
    return true;
}

int main() {
	ios::sync_with_stdio(false);
	cout << (solve() ? "YES" : "NO") << endl;
	return 0;
}