#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int n, d;
	cin >> n >> d;
	for(int i = 0; i < n; i++){
		int v;
		cin >> v;
		
		if(v >= d*10 || v%d == 0){
			cout << "YES" << endl;
		}else{
			bool flag = false;
			while(v > 0){
				if(v%10 == d){
					cout << "YES" << endl;
					flag = true;
					break;
				}
				v-=d;
			}
			if(!flag) cout << "NO" << endl;
		}
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