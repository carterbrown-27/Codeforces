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
	int n;
    cin >> n;
    
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    int prf[n+1];
    prf[0] = 0;
    for(int i = 0; i < n; i++){
        prf[i+1] = prf[i] + a[i];
    }
    
    int sum = prf[n];
    const ll INF = 1e18;
    ll ans = INF;
    
    cout << sum << endl;
    
    for(int k = 2; k <= sum; k++){
        if(sum % k != 0){
            continue;
        }
        
        cout << k << endl;
        ll cost = 0;
        int last = 0;
        for(int i = 0; i < n; i++){
            int cur = (prf[i+1] - prf[last]);
            
            // cout << i+1 << " " << last << " " << cur << endl;
            
            if(cur == 0){
                last = i+1;
                continue;
            }
            
            if(cur == k){
                // cout << i+1 << " " << last << endl;
                // calc cost (congregate to median)
                
                // find median (k 1s -> value j with prf[j-1] = k/2)
                // could binsearch, no need

                auto get_cost = [&] (int m) -> ll {
                    ll c = 0;
                    for(int j = last; j <= i; j++){
                        if(a[j] == 1){
                            cost += abs(j-m);
                        }
                    }
                    return c;
                };
                
                ll mn;
                for(int j = last; j <= i; j++){
                    int v = prf[j] - prf[last];
                    if(v == k/2){
                        mn = get_cost(j); 
                        if(k % 2 == 1)
                            break;
                    }else if(v == k/2 + 1){
                        mn = min(mn, get_cost(j));
                    }
                }
                // cout << "med: " << m << " = " << mn << endl;
                cost += mn;
                last = i+1;
            }
        }
        cout << "=>" << cost << endl;
        ans = min(ans, cost);
    }
    
    cout << (ans == INF ? -1 : ans) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}