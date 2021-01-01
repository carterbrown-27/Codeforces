#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	const int N = 20;
	vector<vector<int>> v(N, vector<int>(N));
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> v[i][j];
		}
	}
	
	int dx[] = {1, 0, 1, 1};
	int dy[] = {0, 1, 1, -1};
	
	int mx = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			for(int d = 0; d < 4; d++){
				int prod = v[i][j];
				bool flag = true;
				int y = i, x = j;
				for(int k = 0; k < 3; k++){
					x += dx[d];
					y += dy[d];
					if(x < 0 || x >= N || y < 0 || y >= N){
						flag = false;
						break;
					}
					prod *= v[y][x];
				}
				
				if(flag && prod > mx){
					mx = prod;
					// printf("%d %d %d\n", i, j, d);
				}
			}
		}
	}
	
	cout << mx << endl;
}

int main() {
	solve();
	return 0;
}