#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int n,x;
	cin >> n >> x;
	int odd = 0;
	for(int i = 0; i < n; i++){
		int v;
		cin >> v;
		odd += (v%2);
	}
	
	int even = n - odd;
	bool works = false;

	for(int i = x-(1-(x%2)); i >= 1; i-=2){
		if(odd >= i && even >= x-i){
			works = true;
		}
	}
	
	cout << (works ? "Yes" : "No") << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}