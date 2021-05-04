#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int n,m;
	cin >> n >> m;
	int ans;
	if(n==1){
		ans = 0;
	}else if(n==2){
		ans = m;
	}else{
		ans = m*2;
	}
	
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}