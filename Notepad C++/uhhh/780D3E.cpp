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
    
    int x = 0;
    bool a[n][n];
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++){
            a[i][j] = (s[j] == '1');
            x += a[i][j];
        }
    }
    
    int b[n][n];
    for(int i = 0; i < n; i++){
        b[i][0] = a[i][0];
        b[0][i] = a[0][i];
    }
    
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            b[i][j] = b[i-1][j-1] + a[i][j];
            //cout << b[i][j];
        }
        //cout << endl;
    }
   
    
    int mxy = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int y;
            if(i == j){
                y = b[n-1][n-1];
            }else if (i < j){
                y = b[i][j] + b[n-1][j-i-1];
            }else{
                y = b[i][j] + b[i-j-1][n-1];
            }
            mxy = max(mxy, y);
        }
    }
    
    int ans = x + n - 2*mxy;
    //cout << x << " " << mxy << endl;
    cout << ans << endl;
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