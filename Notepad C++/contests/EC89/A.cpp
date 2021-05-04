#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int a,b;
	cin >> a >> b;
	int h = max(a,b);
	int l = min(a,b);
	
	int x = h-l;
	x = min(x,l);
	x = min(x,h/2);
	
	h-=2*x;
	l-=x;
	
	if(l==h+1){
		l-=2;
		h-=1;
		x++;
	}
	
	x += (l/3)*2;
	l%=3;
		
	if(l==2){
		x++;
	}
	
	cout << x << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}