#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

template<typename T>
using uset = unordered_set<T>;

const int d8[8][2] = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

#define pb push_back

bool solve() {
	int n, kx, ky;
	cin >> n >> kx >> ky;
	
	// mincheck, minblock
	ll mc[8], mb[8];
	for(int i = 0; i < 8; i++)
		mc[i] = mb[i] = 1e10;
	
	for(int i = 0; i < n; i++){
		char p;
		cin >> p;
		
		int x, y;
		cin >> x >> y;
		
		// unit vector
		int rx = x-kx, ry = y-ky;
		ll dist = (ll) abs(rx) + abs(ry);
		
		// note: can't both be 0
		int ux, uy;
		if(rx == 0){
			ux = 0;
			uy = ry > 0 ? 1 : -1;
		}else if(ry == 0){
			uy = 0;
			ux = rx > 0 ? 1 : -1;
		}else if(abs(rx) == abs(ry)){
			ux = rx > 0 ? 1 : -1;
			uy = ry > 0 ? 1 : -1;
		}else{
			continue;
		}
		// cout << p << " " << ux << " " << uy << endl;
		
		for(int d = 0; d < 8; d++){
			if(ux == d8[d][0] && uy == d8[d][1]){
				// valid direction
				// queen checks
				if(p == 'Q'){
					mc[d] = min(mc[d], dist);
				}
				// could clean this up
				// vert/horiz
				else if(ux == 0 || uy == 0){
					if(p == 'R'){
						mc[d] = min(mc[d], dist);
					}else{
						mb[d] = min(mb[d], dist);
					}
				// diagonal
				}else{
					if(p == 'B'){
						mc[d] = min(mc[d], dist);
					}else{
						mb[d] = min(mb[d], dist);
					}
				}
			}
		}
	}
	
	for(int d = 0; d < 8; d++){
		if(mc[d] < mb[d]){
			// cout << d << " " << mc[d] << " " << mb[d] << endl;
			return true;
		}
	}
	
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cout << (solve() ? "YES" : "NO") << endl;
	return 0;
}