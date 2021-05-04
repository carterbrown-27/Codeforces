#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int n,k;
	cin >> n >> k;
	
	if(n<k || (n%2==1 && k%2==0) || (n%2==0 && k%2==1 && n < 2*k)){
		cout << "NO" << endl;
	}else{
		cout << "YES" << endl;
		if(k%2==0 || n%2==1){
			for(int i = 0; i < k-1; i++){
				cout << "1 ";
			}
			cout << n-k+1 << endl;
		}else{
			for(int i = 0; i < k-1; i++){
				cout << "2 ";
			}
			cout << n-2*k+2 << endl;
		}
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