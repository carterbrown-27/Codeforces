#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int n;
	cin >> n;
	int insegs = 0;
	bool cont = false;
	bool sorted = true;
	for(int i = 1; i <= n; i++){
		int v;
		cin >> v;
		if(v!=i){
			sorted = false;
			if(!cont){
				cont = true;
				insegs++;
			}
		}else{
			cont = false;
		}
	}
	
	cout << (sorted ? 0 : (insegs == 1 ? 1 : 2)) << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}