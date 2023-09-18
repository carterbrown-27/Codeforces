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
	int n, a, b;
    cin >> n >> a >> b;
    
    if(a < b)
        swap(a,b);
    
    int c, d = -1;
    for(c = 0; a*c <= n; c++){
        if(int r = (n - a*c); r % b == 0){
            d = r/b;
            break;
        }
    }
    
    if(d == -1){
        cout << -1 << endl;
        return;
    }
    
    // out << c << " " << d << endl;
    
    int ans[n];
    
    int p = 0, v = 1;
    auto f = [&](int a, int c){
        for(int i = 0; i < c; i++){
            for(int j = p+1; j < p+a; j++){
               ans[j] = v++;
            }
            ans[p] = v++;
            p += a;
        }
    };
    f(a,c);
    f(b,d);
    
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}