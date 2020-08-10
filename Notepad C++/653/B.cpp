#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int n;
	cin >> n;
	int c = 0;
	while(n>1){
		while(n%6==0){
			n/=6;
			c++;
		}
		if(n%3==0){
			n*=2;
			c++;
		}else{
			break;
		}
	}
	
	cout << (n == 1 ? c : -1) << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}