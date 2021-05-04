#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int n,m,x,y;
	cin >> n >> m >> x >> y;
	string sq[n];
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		sq[i] = s;
	}
	
	ll sum = 0;
	for(int b = 0; b < n; b++){
		int len = 0;
		for(int a = 0; a < m; a++){
			if(sq[b][a] == '.'){
				if(++len == 2){
					sum += min(2*x, y);
					len = 0;
				}
			}else{
				sum += len*x;
				len = 0;
			}
		}
		sum += len*x; // if 1 left over
	}
	
	cout << sum << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}