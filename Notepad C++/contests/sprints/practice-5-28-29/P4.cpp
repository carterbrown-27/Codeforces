#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int r;
	cin >> r;
	
	r--;
	for(int i = 1; i*i <= r; i++){
		if(r%i!=0) continue;
		
		int v = r/i - (i+1);
		if(v>=2 && v%2==0){
			cout << i << " " << v/2;
			return;
		}
	}
	
	cout << "NO" << endl;
}

int main() {
	solve();
	return 0;
}