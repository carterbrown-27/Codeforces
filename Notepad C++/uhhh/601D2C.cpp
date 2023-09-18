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
    
    vector<int> fr(n+1);
    vector<vector<int>> tups;
    map<pair<int,int>, vector<int>> mp;
    
    for(int i = 0; i < n-2; i++){
        vector<int> v(3);
        for(int j = 0; j < 3; j++){
            cin >> v[j];
            ++fr[v[j]];
        }
        sort(v.begin(), v.end());
        tups.pb(v);
        
        mp[{v[0], v[1]}].pb(v[2]);
        mp[{v[0], v[2]}].pb(v[1]);
        mp[{v[1], v[2]}].pb(v[0]);
    }
    
    int ans[n];
    
    bool start = false;
    for(auto &v: tups){
        for(int x: v){
            // ans[0] has freq 1, ans[1] freq 2, ans[2..n-2] freq 3.
            ans[fr[x]-1] = x;
            if(fr[x] == 1){
                // start with this tuple
                start = true;
            }
        }

        if(start){
            break;
        }
    }
    
    /*
    for(int i = 0; i < 3; i++)
        cout << ans[i] << " ";
    cout << endl;
    */
    
    if(!start){
        cout << "BAD1" << endl;
        return;
    }
    
    for(int i = 3; i < n; i++){
        int a = ans[i-1], b = ans[i-2];
        if(a > b) swap(a,b);
        
        if(pair<int,int> p = {a,b}; mp.find(p) != mp.end()){
           vector<int> v =  mp[p];
           ans[i] = (v[0] != ans[i-3] ? v[0] : v[1]);
        }else{
            // shouldn't happen
            cout << "@: " << i << " " << ans[i-1] << " " << ans[i-2] << endl;
            return;
        }
    }
    
    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}