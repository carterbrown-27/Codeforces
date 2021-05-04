#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		ll v;
		cin >> v;
		int sqv = (int) sqrt(v);
		if(v > 1 && 1LL*sqv*sqv == v){
			bool flag = true;
			
			for(int j = 2; j <= sqrt(sqv); j++){
				if(sqv%j == 0){
					flag = false;
					break;
				}
			}
			
			if(flag){
				cout << "YES" << endl;
				continue;
			}
		}
		cout << "NO" << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}