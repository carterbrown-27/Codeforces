#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using uset = unordered_set<T>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

#define pb push_back

void solve() {
	int h, w;
	cin >> h >> w;
	
	int b[h][w];
	memset(b, 0, sizeof b);
	
	if(w >= h){
		// top and bottom
		for(int i = 0; i < w; i+=2){
			b[0][i] = 1;
			b[h-1][i] = 1;
		}
		
		for(int i = 2; i < h-2; i+=2){
			b[i][0] = 1;
			b[i][w-1] = 1;
		}
	}else{
		for(int i = 0; i < h; i+=2){
			b[i][0] = 1;
			b[i][w-1] = 1;
		}
		
		for(int i = 2; i < w-2; i+=2){
			b[0][i] = 1;
			b[h-1][i] = 1;
		}
	}
	
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cout << b[i][j];
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