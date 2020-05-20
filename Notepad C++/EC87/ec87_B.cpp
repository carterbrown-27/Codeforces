#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	string s;
	cin >> s;
	int m[3];
	memset(m,-1,sizeof(m));
	int best = 1e8;
	for(int i = 0; i < s.length(); i++){
		m[s[i]-'1'] = i;
		if(m[0] != -1 && m[1] != -1 && m[2] != -1){
			auto res = minmax_element(begin(m),end(m));
			best = min(best,*res.second-*res.first+1);
		}
	}
	cout << (best <= s.length() ? best : 0) << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}