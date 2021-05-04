#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

// solution from reference
void solve() {
	int a,b,c;
	cin >> a >> b >> c;
	
	set<int> cuts;
	for(int i = 1; i <= a; i++){
		cuts.insert(b*c*i);
	}
	for(int i = 1; i <= b; i++){
		cuts.insert(a*c*i);
	}
	for(int i = 1; i <= c; i++){
		cuts.insert(b*a*i);
	}
	
	cout << cuts.size() << endl;
	
	ll prev = 0;
	for(int x: cuts){
		cout << x-prev << " " << (prev / (b*c) + 1) << " " << (prev / (a*c) + 1) << " " << (prev / (a*b) + 1) << endl;
		prev = x;
	}
}

int main() {
	solve();
	return 0;
}