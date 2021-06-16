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
	int n;
	cin >> n;
	
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	int mn = 2e9, mni = -1;
	for(int i = 0; i < n; i++){
		if(a[i] < mn){
			mn = a[i];
			mni = i;
		}
	}
	
	int m = (mn%2 != mni%2);
	int o = mn%2;
	cout << n-1 << endl;
	for(int i = 0; i < n; i++){
		if(i == mni) continue;
		int nv;
		if((i+m)%2 == 0){
			// even
			nv = mn+o;
		}else{
			// odd
			nv = mn+(1-o);
		}
		cout << i+1 << " " << mni+1 << " " << nv << " " << mn << endl;
		a[i] = nv;
		a[mni] = mn;
	}
	
	/*
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	*/
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