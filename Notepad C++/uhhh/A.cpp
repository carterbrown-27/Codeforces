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
	int n, k;
	cin >> n >> k;
	
	if((n+1)/2 < k){
		cout << -1 << endl;
		return;
	}
	
	vector<vector<char>> b(n, vector<char>(n, '.'));
	for(int i = 0; i < k; i++){
		b[i*2][i*2] = 'R';
	}
	
	for(auto r : b){
		for(auto c : r){
			cout << c;
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