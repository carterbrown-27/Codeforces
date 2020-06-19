#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int n,m;
	cin >> n >> m;
	int b[n][m];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> b[i][j];
		}
	}
	
	int cost = 0;
	if(n<=m){
		for(int i = 0; i < m/2 + m%2; i++){
			int j = m-i-1;
			int ones = 0;
			int zeroes = 0;
			for(int d = 0; d < n && i-d >= 0; d++){
				if(b[d][i-d] == 0){
					zeroes++;
				}else{
					ones++;
				}
			
				if(b[n-d-1][j+d] == 0){
					zeroes++;
				}else{
					ones++;
				}
			}
			//cout << i << ": " << ones << " " << zeroes << endl;
			cost += min(ones, zeroes);
		}
	}else{
		for(int i = 0; i < n/2 + n%2; i++){
			int j = n-i-1;
			int ones = 0;
			int zeroes = 0;
			for(int r = 0; r < m && i-r >= 0; r++){
				if(b[i-r][r] == 0){
					zeroes++;
				}else{
					ones++;
				}
			
				if(b[j+r][m-r-1] == 0){
					zeroes++;
				}else{
					ones++;
				}
			}
			// cout << i << ": " << ones << " " << zeroes << endl;
			cost += min(ones, zeroes);
		}
	}
	
	cout << cost << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}