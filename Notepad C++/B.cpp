#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

#define pb push_back

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> tr;
    int b[n][m];
    vector<unordered_set<int>> uv(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> b[i][j];
            tr.pb({b[i][j], i, j});
            uv[i].insert(j);
        }
    }

    sort(tr.begin(), tr.end());
    for(int r = 0; r < m; r++){
        uv[tr[r][1]].erase(tr[r][2]);
    }

    for(int i = 0; i < n; i++){
        for(int r = 0; r < m; r++){
            int c;
            if(tr[r][1] == i){
                c = tr[r][0];
            }else{
                int j = *(uv[i].begin());
                c = b[i][j];
                uv[i].erase(j);
            }
            cout << c << " ";
        }
        cout << endl;
    }
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