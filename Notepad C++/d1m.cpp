#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	vector<int> num;
	for(int i = 0; i < 20; i++){
		string s;
		cin >> s;
	
		for(char c: s){
			num.push_back(c-'0');
		}
	}
	
	const int LEN = 13;
	ll mx = 0;
	for(int i = 0; i <= num.size() - LEN; i++){
		ll prod = 1;
		for(int j = i; j < i + LEN; j++){
			prod *= num[j];
		}
		mx = max(mx, prod);
	}
	
	cout << mx << endl;
	
	// 23514624000
}

int main() {
	solve();
	return 0;
}