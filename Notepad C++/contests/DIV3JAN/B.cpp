#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int n;
	cin >> n;
	int ones = 0, twos = 0;
	for(int i = 0; i < n; i++){
		int v;
		cin >> v;
		if(v == 1){
			ones++;
		}else{
			twos++;
		}
	}
	
	if(ones%2 == 1 || (twos % 2 == 1 && ones < 2)){
		cout << "NO\n";
	}else{
		cout << "YES\n";
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