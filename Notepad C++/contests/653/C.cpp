#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int unc = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '('){
			unc++;
		}else if(unc > 0){
			unc--;
		}
	}
	
	int uno = 0;
	for(int i = n; i-- > 0;){
		if(s[i] == ')'){
			uno++;
		}else if(uno > 0){
			uno--;
		}
	}
	
	cout << min(uno,unc) << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}