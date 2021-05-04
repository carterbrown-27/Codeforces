#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int n,m;
	cin >> n >> m;
	
	int lb = m;
	int hb = m;
	bool works = true;
	int last = 0;
	for(int i = 0; i < n; i++){
		int t,l,h;
		cin >> t >> l >> h;
		
		if(!works) continue; // reads in remaining lines
		
		int dt = t-last;
		lb -= dt;
		hb += dt;
		last = t;
		
		if((l <= lb && lb <= h) || (l <= hb && hb <= h) || (lb <= l && h <= hb)){
			lb = max(l,lb);
			hb = min(h,hb);
		}else{
			works = false;
		}
		
	}
	
	cout << (works ? "YES" : "NO") << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}