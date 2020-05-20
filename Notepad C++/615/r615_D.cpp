#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int q,x;
	cin >> q >> x;
	
	int mod[x]{0};
	int mex = 0;
	for(int i = 0; i < q; i++){
		int y;
		cin >> y;
		mod[y%x]++;
		
		for(; mod[mex%x] > 0; mex++){
			mod[mex%x]--;
		}
	
		cout << mex << endl;
	}
}

int main() {
	solve();
	return 0;
}