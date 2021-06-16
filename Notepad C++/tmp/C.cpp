#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

#define pb push_back

void solve() {
    int n;
    cin >> n;

    int p[n]; 
    for(int i = 0; i < n; i++) cin >> p[i];

    vector<vector<int>> b;
    for(int i = 1; i <= n; i++){
        b.pb(vector<int>(i));
    }

    for(int i = 0; i < n; i++){
        int x, y;
        x = y = i;
        int v = p[i];

        int c = 0;
        while(c < v && x >= 0 && y < n){
            b[y][x] = v;
            c++;

            if(x-1 >= 0 && b[y][x-1] == 0){
                x--;
            }else if(y+1 < n && b[y+1][x] == 0){
                y++;
            }else{
                break;
            }
        }

        if(c < v){
            cout << -1 << endl;
            return;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i+1; j++){
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}