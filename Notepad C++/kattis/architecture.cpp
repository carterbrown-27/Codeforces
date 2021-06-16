#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

template<typename T>
using uset = unordered_set<T>;

#define pb push_back

int main() {
	ios::sync_with_stdio(false);
	
	int m, n;
	cin >> m >> n;
	
	int x[m], y[n];
	
	for(int r = 0; r < m; r++)
		cin >> x[r];
	
	for(int c = 0; c < n; c++)
		cin >> y[c];
	
	for(int r = 0; r < m; r++){
		bool works = false;
		for(int c = 0; c < n; c++){
			if(y[c] >= x[r]){
				works = true;
				break;
			}
		}
		if(!works){
			cout << "impossible" << endl;
			return 0;
		}
	}
	
	for(int c = 0; c < n; c++){
		bool works = false;
		for(int r = 0; r < m; r++){
			if(x[r] >= y[c]){
				works = true;
				break;
			}
		}
		if(!works){
			cout << "impossible" << endl;
			return 0;
		}
	}
	
	cout << "possible" << endl;
	return 0;
}