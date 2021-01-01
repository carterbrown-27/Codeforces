#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int a,b,x,y,n;
	cin >> a >> b >> x >> y >> n;
	
	int la = max(a-n, x);
	int lb = max(b-n, y);
	
	int fa = a, fb = b;
	if(la <= lb){
		fa = la;
		n -= (a-la);
		fb = max(b-n, y);
	}else{
		fb = lb;
		n -= (b-lb);
		fa = max(a-n, x);
	}
	
	cout << 1ll * fa * fb << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}