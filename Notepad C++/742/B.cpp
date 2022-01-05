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
	int a, b;
	cin >> a >> b;
	
	int k = a;
	int n = a-1;
	int x;
	int r = n % 4;
	
	if(r == 0){
		x = n;
	}else if(r == 1){
		x = 1;
	}else if(r == 2){
		x = n+1;
	}else{
		x = 0;
	}
	
	if(x == b){
		cout << k << endl;
	}else if((x^b) != a){
		// insert x ^ b
		cout << k + 1 << endl;
	}else{
		cout << k + 2 << endl;
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