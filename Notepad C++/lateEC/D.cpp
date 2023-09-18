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
    string s;
    cin >> s;
    
    int n = s.length();
    
    int outs[n];
  
    for(int i = 0; i < n; i++){
        // end here
        
        // alice first, she picks
        bool bob = false;
        auto f = [&](int l, int r, const auto& self) -> bool {
                cout << l << " " << r << endl;
                if(l >= r){
                    return false;
                }
                int a = l, b = r;
                // equal on sides == ?? 
                for(; l < r && s[l] == s[a]; l++);
                for(; r > l && s[r] == s[b]; r--);
                
                int amt = l-a + b-r;
                
                if(amt%2 == 1){
                    return true;
                }else{
                    return self(l, r, self);
                }
        };
        auto check = [&](int l, int r) -> bool{
            char b = s[i];
            
            if(s[l] < b || s[r] < b){
                return true;
            }else if(s[l] > b && s[r] > b){
                bob = true;
                return false;
            }else{
                return f(l,r,f);
            }      
        };
        
        outs[i] = 2;
        
        if(i>0)
            if(check(0, i-1)){
                outs[i] = (n-1-i)%2;
            }    
        if(i<n-1)
            if(check(i+1, n-1)){
                bool b = (i-1)%2;
                if(outs[i] == 2){
                    outs[i] = b;
                }else if(outs[i] == 0){
                    outs[i] = (b ? 2 : 0)
                }else if(outs[i] == 1){
                    outs[i] = (b ? 2 : 1);
                }
            }
        
        
        if(outs[i] != 2)
            continue;
        
        if(bob){
            outs[i] = 1;
        }else{
            outs[i] = 2;
        }
    }
    for(int i = 0; i < n; i++)
        cout << outs[i] << " ";
    cout << endl;
    
    
    // game
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