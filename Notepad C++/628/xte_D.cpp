#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve(){
	ll u,v;
	cin >> u >> v;
	
	if(u>v || u%2!=v%2){
		cout << -1 << endl;
	}else if(u==v){
		if(u==0){
			cout << 0 << endl;
		}else{
			cout << 1 << endl;
			cout << u << endl;
		}
	}else{
		// u < v
		ll x = (v-u)/2;
		if(u&x == 0){
			cout << 2 << endl;
			printf("%I64d %I64d\n",u^x,x);
		}else{
			cout << 3 << endl;
			printf("%I64d %I64d %I64d\n",u,x,x);
		}
	}
}

int main() {
	solve();
	return 0;
}