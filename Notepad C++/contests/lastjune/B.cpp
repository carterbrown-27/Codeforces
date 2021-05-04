#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int n;
	cin >> n;
	
	if(n%2 == 0){
		cout << n/2 << " " << n/2 << endl;
		return;
	}else{
		for(int i = sqrt(n); i >= 1; i--){
			if((n-i)%i == 0){
				cout << i << " " << n-i << endl;
				return;
			}
		}
	}
	
	cout << 1 << " " << n-1 << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}