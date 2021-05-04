#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int w, h, n;
	cin >> w >> h >> n;
	int wd = 1, hd = 1;
	while(w % 2 == 0){
		wd*=2;
		w/=2;
	}
	
	while(h % 2 == 0){
		hd*=2;
		h/=2;
	}
	
	if(wd*hd >= n){
		cout << "YES\n";
	}else{
		cout << "NO\n";
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