#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	string s;
	cin >> s;
	bool allsame = true;
	char f = s[0];
	for(char c: s){
		if(c!=f){
			allsame = false;
			break;
		}
	}
	
	string period;
	if(allsame){
		period = f;
	}else{
		period = "10";
	}
	
	string ans = "";
	for(int i = 0; i < s.length(); i++){
		ans.append(period);
	}
	
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}