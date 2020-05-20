#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int n,m;
	cin >> n >> m;
	int a[n][m];
	ll ans = 0;
	
	for(int y = 0; y < n; y++){
		for(int x = 0; x < m; x++){
			scanf("%d", &a[y][x]);
			if(a[y][x] % m != (x+1)%m){
				a[y][x] = 0; // wildcard
			}
		}
	}
	
	for(int x = 0; x < m; x++){
		// no time right now, but compute offsets for each #, pick most frequent, all others don't
		int offset[n];
		for(int y = 0; y < n; y++){
			if(a[y][x] == 0){
				offset[y] = n;
				continue;
			}
			int dest = (a[y][x]-1)/m;
			// cout << dest << endl;
			if(dest<=y){
				offset[y] = y-dest;
			}else{
				offset[y] = y+(n-dest);
			}
		}
		
		// cout << "here1" << endl;
		int offTally[n+1]{0};
		for(int i: offset){
			offTally[i]++;
			//cout << i << " ";
		}
		
		//cout << endl;
		// cout << "here2" << endl;
		
		int mx = 0;
		int mi = -1;
		for(int i = 0; i < n; i++){
			if(offTally[i] > mx){
				mx = offTally[i];
				mi = i;
			}
		}
		
		//cout << mx << " " << mi << endl;
		ans+=mi;
		
		for(int i: offset){
			if(i != mi){
				ans++;
			}
		}
	}
	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}