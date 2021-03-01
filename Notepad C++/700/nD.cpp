#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int n;
	cin >> n;
	
	int segs = 0;
	int last = -1, c = 0;
	for(int i = 0; i < n; i++){
		int v;
		cin >> v;
		if(v == last){
			c++;
		}else{
			segs += min(c, 2);
			c = 1;
			last = v;
		}
	}
	
	cout << segs << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}