#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int n;
	cin >> n;
	int x = 1;
	vector<int> smds;
	while(n>0){
		if(n%x != 0){
			smds.push_back(n%x);
		}
		n-=n%x;
		x*=10;
	}
	
	cout << smds.size() << endl;
	for(auto x: smds){
		cout << x << " ";
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}