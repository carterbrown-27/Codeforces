#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	int x,y,x1,y1,x2,y2;
	cin >> x >> y >> x1 >> y1 >> x2 >> y2;
	
	int u = x+b-a;
	int v = y+d-c;

	if(x1 <= u && u <= x2 && y1 <= v && v <= y2 && !((d+c > 0)&& (y2-y1==0)) && !((a+b > 0)&& (x2-x1==0))){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
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