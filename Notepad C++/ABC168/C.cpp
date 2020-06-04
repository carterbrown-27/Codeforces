#include <bits/stdc++.h>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int a,b,h,m;
	cin >> a >> b >> h >> m;
	
	// each hr = 30deg, each minute = .5 deg
	double hp = 30*h + 0.5*m;
	// each minute = 6 degrees
	double mp = ((60*h + m) % 60) * 6;
	double ang = abs(hp-mp);
	
	double c = sqrt(a*a + b*b - 2*a*b*cos(ang*M_PI/180.0));
	
	cout.precision(15);
	cout << c << endl;
}

int main() {
	solve();
	return 0;
}