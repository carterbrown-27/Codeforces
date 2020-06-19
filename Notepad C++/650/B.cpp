#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define push_back pb
#define make_pair mp

void solve() {
	int n;
	cin >> n;
	
	int badOdd = 0;
	int badEven = 0;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(x%2 != i%2){
			if(x%2 == 0){
				badEven++;
			}else{
				badOdd++;
			}
		}
	}
	
	if(badOdd == badEven){
		cout << badOdd << endl;
	}else{
		cout << -1 << endl;
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