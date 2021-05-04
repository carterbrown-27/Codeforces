#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int n;
	cin >> n;
	bool a[101]{false};
	int evens = 0;
	int odds = 0;
	for(int i = 0; i < n; i++){
		int val;
		cin >> val;
		a[val] = true;
		if(val%2==0){
			evens++;
		}else{
			odds++;
		}
	}
	evens%=2;
	odds%=2;
	
	if(evens==1 && odds==1){
		for(int i = 1; i <= 100; i++){
			if(a[i] && a[i-1]){
				evens--;
				odds--;
				break;
			}
		}
	}
	
	cout << (evens==0 && odds==0 ? "YES" : "NO") << endl;
	
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}