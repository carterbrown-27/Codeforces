#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

/*
 * Given an n*m matrix G, and values a,b {a <= m && b <= n}, 
 * 1. Determine if it is possible to fill the matrix with 0's and 1's such that:
 * 		Each row has exactly a 1's, and each column has exactly b 1's.
 * 2. If it is possible, print the matrix.
 */
void solve() {
	int n,m,a,b;
	cin >> n >> m >> a >> b;
	
	if(n*a != m*b){
		cout << "NO" << endl;
		return;
	}else{
		cout << "YES" << endl;
	}
	
	string s = "";
	for(int i = 0; i < m; i++){
		s += (i<a ? "1" : "0");
	}
	
	int shift = 0;
	for(int i = 0; i < n; i++){
		for(int j = shift; j < shift+m; j++){
			cout << s[j%m];
		}
		cout << endl;
		shift+=a;
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}