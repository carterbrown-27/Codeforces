#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int n,x;
	cin >> n >> x;
	
	int inc = 1;
	for(int i = 0; i < n-1; i++){
		int u,v;
		cin >> u >> v;
		if(u==x || v==x){
			inc++;
		}
	}
	
	if(inc <= 2 || n%2==0){
		cout << "Ayush" << endl;
	}else{
		cout << "Ashish" << endl;
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