#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int n, x;
	cin >> n >> x;
	
	ll sum = 0;
	int a[n];
	int b[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		b[i] = a[i];
		sum += a[i];
	}
	
	bool flag = false;
	
	while(!flag){
		for(int i = 0; i < n; i++){
			if(b[i] % x != 0){
				flag = true;
				break;
			}else{
				sum += a[i];
				b[i] /= x;
			}
			//cout << b[i] << " ";
		}
		//cout << endl;
	}
	
	cout << sum << "\n";
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}