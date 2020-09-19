#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	ll sum = 0;
	for(int i = 3; i < 1e6; i+=3){
		sum += i;
	}
	
	for(int i = 5; i < 1e6; i+=5){
		if(i%3 != 0) sum += i;
	}
	
	cout << sum << endl;
}

int main() {
	solve();
	return 0;
}