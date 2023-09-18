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

void solve() {
    srand(time(NULL));
    int i = 4;
    
	while(true){
        int x = rand()%(i-1) + 1;
        
        cout << "? " << x << " " << i << endl;
        ll r;
        cin >> r;
        
        if(r == -1){
            cout << "! " << i-1 << endl;
            return;
        }0
        
        cout << "? " << i << " " << x << endl;
        ll s;
        cin >> s;
        
        if(r != s){
            cout << "! " << r+s << endl;
            return;
        }
        i++;
    }
    // cout << "! " << 27 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}