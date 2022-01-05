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
	string num; 
	cin >> num;
	
	vector<int> digs;
	for(char c: num)
		digs.pb(c-'0');
	
	int n = digs.size();
	
	vector<ll> cr(3);
	cr[0] = 1;
	
	for(int i = n; i-- > 0;){
		int d = digs[i];
		
		vector<ll> tmp(3);
		
		tmp[0] = (d+1)*(cr[0] + (i > 0 ? cr[1] : 0)) + d*cr[2];

		tmp[1] = cr[2];

		tmp[2] = (9-d)*(cr[0] + (i > 0 ? cr[1] : 0)) + (9-d+1)*cr[2];		
			
		cr = tmp;
		cout << cr[0] << " " << cr[1] << " " << cr[2] << endl;
	}
	
	cout << cr[0] << endl;
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