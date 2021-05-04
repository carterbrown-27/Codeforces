#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int n;
	cin >> n;
	int nsq = n*n;
	
	int x = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n/2; j++){
			cout << x << " " << nsq-x+1 << " ";
			x++;
		}
		cout << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}